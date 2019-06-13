from django.urls import resolve
from django.views import View
from onlineapp.models import *
from django.shortcuts import render,redirect
from onlineapp.forms import college
from django.contrib.auth.mixins import LoginRequiredMixin
from django.contrib.auth.models import Permission
class CollegeView(LoginRequiredMixin,View):
    login_url = 'login'
    def get(self,request,*args,**kwargs):
        permissions = list(request.user.get_all_permissions())
        username=request.user.username;
        if(kwargs):
                students = Student.objects.values('id','name', 'mocktest1__total').filter(college__id=kwargs['id']).order_by("-mocktest1__total")
                college = College.objects.values('name','id').filter(id=kwargs['id'])
                college = college[0]
                return render(
                    request,
                    template_name="index1.html",
                    context={
                        "values": students,
                        "college": college,
                        "permissions":permissions,
                        "username":username
                    }
                )
        colleges=College.objects.all()
        return render(
            request,
            template_name="college.html",
            context={
                "values":colleges,
                "permissions": permissions,
                "username": username
            }
        )
class AddCollegeView(View):
    def get(self,request,*args,**kwargs):
        form=college.CollegeForm()
        if resolve(request.path_info).url_name=='delete':
            College.objects.get(id=kwargs['id']).delete()
            return redirect("colleges")
        if kwargs:
            coll=College.objects.get(**kwargs)
            form=college.CollegeForm(instance=coll)
        return render(
            request,
            template_name="Addform.html",
            context={
                "form":form
            }
         )
    def post(self,request,*args,**kwargs):
        form=college.CollegeForm(request.POST)
        if resolve(request.path_info).url_name == 'edit':
            colleg=College.objects.get(id=kwargs['id'])
            form=college.CollegeForm(request.POST,instance=colleg)
        if(form.is_valid()):
            form.save()
            return redirect("colleges")
        form = college.CollegeForm()
        return render(
            request,
            template_name="Addform.html",
            context={
                "form": form
            }
        )