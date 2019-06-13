from django.urls import path
from onlineapp import views
from onlineapp.views import college,students,loginforms
from onlineapp.views import CollegeSerilization,StudentSerilization
urlpatterns = [
path('colleges/',college.CollegeView.as_view(),name="colleges"),
path('colleges/<int:id>/',college.CollegeView.as_view(),name="students"),
path('colleges/<int:id>/add',students.AddStudentView.as_view(),name="AddStudent"),
path('colleges/<int:id>/<int:id2>/edit',students.AddStudentView.as_view(),name="editStudent"),
path('colleges/<int:id>/<int:id2>/delete',students.AddStudentView.as_view(),name="deleteStudent"),
path('colleges/add',college.AddCollegeView.as_view(),name="Addcollege"),
path('colleges/<int:id>/edit',college.AddCollegeView.as_view(),name="edit"),
path('colleges/<int:id>/delete',college.AddCollegeView.as_view(),name="delete"),
path('login/',loginforms.loginView.as_view(),name='login'),
path('signup/',loginforms.signupView.as_view(),name='Signup'),
path('logout/',loginforms.logout_user,name ="logout"),
path('api/college',CollegeSerilization.CollegeSerilizerView,name="apiserilizer"),
path('api/college/<int:id>',CollegeSerilization.CollegeSerilizerView,name="apiserilizer1"),
path('api/college/<int:id1>/students',StudentSerilization.StudentSerilizerView.as_view(),name="apistuserilizer")
]