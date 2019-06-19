from django.urls import resolve
from django.views import View
from django.db.models import Sum,Count
from ipl.models import *
from django.shortcuts import render,redirect
from django.contrib.auth.mixins import LoginRequiredMixin
def get_points_dict(season):
    query = Matches.objects.all().values("winner").filter(season=season).annotate(dsum=Count('result')).order_by('-dsum')
    last =Matches.objects.all().filter(season=season).order_by('-id')
    count=(Matches.objects.values('team1').filter(season=season).distinct().count() -1 )*2
    print(Matches.objects.all().filter(season=season).count())
    print(count)
    if(season in [2009,2008,2010]):
        leavemat=3
    else:
        leavemat=4
    points = []
    for match in query:
        match1=[]
        if (match['winner'] != None):
            match1.append(match['winner'])
            match1.append(count)
            match1.append(match['dsum'])
            match1.append(count - (match['dsum']))
            match1.append((match['dsum'])*2)
        if(match1 !=[]):
            points.append(match1)
    for index in range(leavemat):
        for match1 in points:
            if(match1[0]==last[index].winner):
                match1[2] -=1
                match1[3] +=1
                match1[4] -=2
    noresult=Matches.objects.all().filter(season=2019, winner=None).order_by('-id')
    for match in noresult:
        print(match.team1,match.team2)
        for match1 in points:
            if(match1[0]==match.team1 or match.team2==match1[0]):
                match1[4]+=1
    return points
class ipltableView(View):
    def get(self,request,*args,**kwargs):
        username = request.user.username
        years = [2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019]
        if kwargs:
            points=get_points_dict(kwargs["id1"])
            winner=Matches.objects.all().filter(season=kwargs["id1"]).order_by('-id')[0].winner
            year=kwargs["id1"]
        else:
            points=get_points_dict(2019)
            winner = Matches.objects.all().filter(season=2019).order_by('-matchid')[0].winner
            year=2019
        return render(
            request,
            template_name="iplpoints.html",
            context={
                "points":points,
                "Winner":winner,
                "years":years,
                "pyear":year,
                "username":username,
                "chennai":"Chennai Super Kings"
            }
        )






