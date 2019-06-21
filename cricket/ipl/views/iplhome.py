from django.urls import resolve
from django.views import View
from django.db.models import Sum,Count,Q
from ipl.models import *
from ipl.views import iplpointstable
from django.shortcuts import render,redirect
from django.contrib.auth.mixins import LoginRequiredMixin
class IplHomeView(View):
    def get(self,request,*args,**kwargs):
        username=request.user.username
        points=iplpointstable.get_points_dict(2019)
        short_names={
            "Sunrisers Hyderabad": "SRH",
            "Mumbai Indians": "MI",
            "Royal Challengers Bangalore": "RCB",
            "Kolkata Knight Riders": "KKR",
            "Kings XI Punjab": "KXIP",
            "Chennai Super Kings": "CSK",
            "Rajasthan Royals": "RR",
            "Delhi Capitals": "DC",
            "Gujarat Lions": "GL",
            "Rising Pune Supergiant": "RPS",
            "Pune Warriors": "PW",
            "Kochi Tuskers Kerala": "KTKER",
            "Deccan Chargers":"DEC",
            "Delhi Daredevils":"DD",
        }
        for team in points:
            team[0]=short_names[team[0]]
        li=[]
        playofs=['Final','Qualifier2','Eliminator','Qualifier1']
        query=Matches.objects.all().filter(season=2019).order_by("-id")[0:4]
        for index in range(4):
            m=[]
            m.append(query[index].team1)
            m.append(query[index].team2)
            m.append(playofs[index])
            m.append(query[index].venue)
            m.append(query[index].season)
            m.append(query[index].matchid)
            li.append(m)
        batsmans=Deliviers.objects.all().values("batsman").annotate(dsum=Sum('batsman_runs') ).order_by('-dsum')[:10]
        bowlers=Deliviers.objects.all().values("bowler").filter(~Q(dismissal_kind='runout')).annotate(dsum=Count('player_dismissed')).order_by('-dsum')[:10]
        return render(
            request,
            template_name="iplhome.html",
            context={
                "points": points,
                "username": username,
                "playoffs":li,
                "Batsman":batsmans,
                "Bowler":bowlers
            }
        )


