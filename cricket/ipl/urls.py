from django.urls import path
from ipl.views import iplsummary,loginforms,iplpointstable,iplteams
urlpatterns = [
    path('summary/',iplsummary.iplView.as_view(),name="iplsummary"),
    path('summary/<int:id1>/<str:id2>/', iplsummary.indMatchView.as_view(), name="oplidstr"),
    path('summary/<int:id1>/',iplsummary.iplView.as_view(),name="oplidsummary"),
    path('summary/<int:id1>/<int:id2>/',iplsummary.indMatchView.as_view(),name="iplindmatch"),
    path('summary/<int:id1>/<int:id2>/<int:id3>', iplsummary.indMatchView.as_view(), name="innings"),
    path('login/',loginforms.loginView.as_view(),name="login"),
    path('signup/',loginforms.signupView.as_view(),name="Signup"),
    path('logout/',loginforms.logout_user,name ="logout"),
    path('points-table/',iplpointstable.ipltableView.as_view(),name="points"),
    path('points-table/<int:id1>/',iplpointstable.ipltableView.as_view(),name="points"),
    path('teams/',iplteams.IplTeamView.as_view(),name="teams"),
    path('teams/<int:id1>/',iplteams.IplTeamView.as_view(),name="perteam")
]