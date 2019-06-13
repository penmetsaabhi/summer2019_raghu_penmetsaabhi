from onlineapp.models import College,Student,MockTest1
from rest_framework import routers, serializers, viewsets
from rest_framework.serializers import ModelSerializer
class CollegeSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = College
        fields = ('name','location','acronym','contact')

class StudentSerilizer(ModelSerializer):
    class Meta(object):
        model = Student
        fields = ('name', 'dob', 'email', 'db_folder', 'dropped_out')
class MockSerilizer(ModelSerializer):
    student =StudentSerilizer(many=True, read_only=True)
    class Meta(object):
        model = MockTest1
        fields = ('student','problem1', 'problem2', 'problem3', 'problem4', 'total')

