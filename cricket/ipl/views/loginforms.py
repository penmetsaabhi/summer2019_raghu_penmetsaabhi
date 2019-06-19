from django.urls import resolve
from django.views import View
from ipl.models import *
from django.shortcuts import render,redirect
from ipl.forms import loginforms
from django.contrib.auth import authenticate,login,logout
from django.contrib import messages
from django.contrib.auth.models import User
from django.http import HttpResponse
from django.contrib.auth.mixins import LoginRequiredMixin
def logout_user(request):
    logout(request)
    return redirect('login')
class loginView(View):
    def get(self,request,*args,**kwargs):
        login=loginforms.loginForm()
        return render(
            request,
            template_name='loginForm.html',
            context={
                'log':login
            }
        )
    def post(self,request,*args,**kwargs):
        username=request.POST['username']
        password=request.POST['password']
        user=authenticate(request,username=username,password=password)
        if user is not None:
            login(request,user)
            return redirect('iplsummary')
        else:
            messages.error(request,'Invalid credintials')
            return redirect('login')
class signupView(View):
    def get(self,request,*args,**kwargs):
        signup=loginforms.signupForm()
        return render(
            request,
            template_name='signup1.html',
            context={
                'log':signup
            }
        )
    def post(self,request,*args,**kwargs):
        form=loginforms.signupForm(request.POST)
        if( form.is_valid()):
            try:
                user=User.objects.create_user(username=request.POST['username'], password=request.POST['password'],first_name=request.POST['firstname'],
                                    last_name=request.POST['lastname'])
                user.save()
            except:
                messages.error(request, 'Invalid credintials')
                return redirect('Signup')
            return redirect('login')
        else:
            messages.error(request,'Invalid credintials')
            return redirect("signup")