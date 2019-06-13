from rest_framework.decorators import api_view
from rest_framework import viewsets
from onlineapp.serilization import StudentSerilizer,MockSerilizer
from onlineapp.models import College,Student,MockTest1
from rest_framework.response import Response
from rest_framework import status
from rest_framework.views import APIView
class StudentSerilizerView(APIView):
    def get(self,request,**kwargs):
        college=College.objects.all().filter(id=kwargs['id1'])
        mock=MockTest1.objects.values('problem1','problem2','problem3','problem4','total').filter(college=college)
        serilizer_class=MockSerilizer(instance=mock)
        return  Response(serilizer_class.data)


