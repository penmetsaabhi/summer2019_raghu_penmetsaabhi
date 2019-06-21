from django.urls import resolve
from django.views import View
from django.db.models import Sum,Count,Max,Q
from ipl.models import *
from django.shortcuts import render,redirect
from django.contrib.auth.mixins import LoginRequiredMixin
class IplTeamView(View):
    def get_list(self):
        teams = Matches.objects.values("team1").distinct();
        match = Matches.objects.all().values('season').annotate(dsum=Max('matchid')).order_by('season')
        list = []
        for team in teams:
            if team['team1'] != 'Delhi Daredevils' and team['team1'] != "Rising Pune Supergiants" and team[
                'team1'] != "Deccan Chargers":
                list.append([team['team1']])
        for id in match:
            winner = Matches.objects.values('winner').filter(matchid=id['dsum'])[0]
            winner = winner['winner']
            for team in list:
                if (team[0] == winner):
                    team.append(id['season'])
        return list
    def get_team_by_season(self,team):
        years=[2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018,2019]
        li=[]
        for year in years:
            played = Matches.objects.all().filter(team1=team,season=year).count() + Matches.objects.all().filter(team2=team,season=year).count()
            print(played)
            if(played==0):
                li.append([year,"~","~","~","~"])
            else:
                won = Matches.objects.all().filter(winner=team, season=year).count()
                match=[year,played,won,played-won]
                if year in [2008,2009,2010]:
                    query=Matches.objects.values('team1', 'team2', 'matchid').filter(season=year).order_by('-matchid')[0:3]
                else:
                    query = Matches.objects.values('team1', 'team2', 'matchid').filter(season=year).order_by(
                        '-matchid')[0:4]
                Teams=[]
                for i in query:
                    if(i['team1'] not in Teams):
                        Teams.append(i['team1'])
                    if(i['team2'] not in Teams):
                        Teams.append(i['team2'])
                print(Teams, year)
                winner = Matches.objects.all().filter(season=year).order_by('-matchid')[0].winner
                if(winner==team):
                    match.append("Champion")
                elif(team in Teams):
                    match.append("Play offs")
                else:
                    match.append("League Stage")
                li.append(match)
        return li

    def get(self,request,*args,**kwargs):
        username = request.user.username
        if kwargs:
            ids= {
                "1":"Sunrisers Hyderabad",
                "2":"Mumbai Indians",
                "3":"Royal Challengers Bangalore",
                "4":"Kolkata Knight Riders",
                "5":"Kings XI Punjab",
                "6":"Chennai Super Kings",
                "7":"Rajasthan Royals",
                "8":"Delhi Capitals",
                "9":"Gujarat Lions",
                "10":"Rising Pune Supergiant",
                "11":"Pune Warriors",
                "12":"Kochi Tuskers Kerala",
            }

            team=ids[str(kwargs["id1"])]
            li2 = self.get_team_by_season(team)
            print(li2)
            played= Matches.objects.all().filter(team1=team).count()+ Matches.objects.all().filter(team2=team).count()
            noresult=Matches.objects.all().filter(team1=team,winner=None).count() + Matches.objects.all().filter(team2=team,winner=None).count()
            won= Matches.objects.all().filter(winner=team).count()
            li=[["Matches Played",played],["Won",won],["Lost",played-won-noresult],["noresult",noresult]]
            batsmans=Deliviers.objects.values('batsman').filter(batting_team=team).annotate(
                dsum=(Sum('batsman_runs'))).order_by("-dsum")[:5]
            bowlers=  Deliviers.objects.values('bowler').filter(~Q(dismissal_kind='runout'),bowling_team=team).annotate(
                dsum=(Count('player_dismissed'))).order_by("-dsum")[0:5]
            return render(
                request,
                template_name="perteam.html",
                context={
                    "played":li,
                    "batsmans":batsmans,
                    "bowlers":bowlers,
                    "stats":li2,
                    "team":team,
                    "username":username
                }
            )

        list=self.get_list()
        return render(
            request,
            template_name="team.html",
            context={
                "teams": list,
                "username": username,
            }
        )