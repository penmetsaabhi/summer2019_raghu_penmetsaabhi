from django.urls import resolve
from django.views import View
from django.db.models import Sum,Count
from ipl.models import *
from django.shortcuts import render,redirect
from django.contrib.auth.mixins import LoginRequiredMixin
class iplView(View):
    def get(self,request,*args,**kwargs):
        username = request.user.username
        if(kwargs):
            matches = Matches.objects.all().filter(season=kwargs["id1"])[:8]
            count1 = Matches.objects.all().filter(season=kwargs["id1"]).count()
            yr=kwargs["id1"]
        else:
            matches=Matches.objects.all().filter(season=2019)[0:8]
            count1 = Matches.objects.all().filter(season=2019).count()
            yr=2019

        pre=None
        if (8 < count1):
            next = "8" + "-" + "16"
        else:
            next = None
        years=[2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018,2019]
        return render(
            request,
            template_name="iplsum.html",
            context={
                "values":matches,
                "years":years,
                "pyear":yr,
                "pre":pre,
                "next":next,
                "count":count1,
                "username":username
            }
        )
class indMatchView(LoginRequiredMixin,View):
    login_url = 'login'
    def get(self,request,*args,**kwargs):
        username = request.user.username
        if type(kwargs["id2"]).__name__=='str' and '-' in kwargs["id2"]:
            return (self.paging(request,kwargs["id1"],kwargs["id2"]))
        else:
            if "id3" in kwargs:
                matches=Matches.objects.all().filter(season=kwargs["id1"],matchid=kwargs["id2"])[0]
                commentry=Deliviers.objects.all().filter(match1_id=kwargs["id2"],inning=kwargs["id3"])
                innings=kwargs["id3"]
            else:
                matches = Matches.objects.all().filter(season=kwargs["id1"], matchid=kwargs["id2"])[0]
                commentry = Deliviers.objects.all().filter(match1_id=kwargs["id2"], inning=1)
                innings=1
            batsman=Deliviers.objects.values("batsman").filter(match1_id=kwargs["id2"]).annotate(dsum=Sum("batsman_runs")).order_by("-dsum")[:3]
            bowler=Deliviers.objects.values("bowler").filter(match1_id=kwargs["id2"]).annotate(dsum=Count("player_dismissed")).order_by("-dsum")[:3]
            return render(
                request,
                template_name="iplmatch.html",
                context={
                    "values": matches,
                    "comm":commentry,
                    "year":kwargs["id1"],
                    "match":kwargs["id2"],
                    "innings":innings,
                    "batsmans":batsman,
                    "bowlers":bowler,
                    "username":username
                 }
             )
    def paging(self,request,season,string):
        username = request.user.username
        li=string.split("-")
        val1=int(li[0])
        val2=int(li[1])
        pre=None
        count=Matches.objects.all().filter(season=season).count()
        matches = Matches.objects.all().filter(season=season)[val1:val2]
        yr = season
        if(val1!=1):
            pre=str((val1-8))+ "-"+str((val1))
        if(val2<count):
            next=str((val2))+"-"+str((val2+8))
        else:
            next=None
        years = [2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019]
        return render(
            request,
            template_name="iplsum.html",
            context={
                "values": matches,
                "years": years,
                "pyear": yr,
                "pre": pre,
                "next": next,
                "username":username
            }
        )
