from rest_framework.decorators import api_view
from onlineapp.serilization import CollegeSerializer
from onlineapp.models import College
from rest_framework.response import Response
from rest_framework import status
@api_view(['GET','POST','PUT','DELETE'])
def CollegeSerilizerView(request,**kwargs):
    """
    API endpoint that allows users to be viewed or edited.
    """
    if(request.method=='GET'):
        if(kwargs):
            queryset=College.objects.all().filter(id=kwargs['id'])
        else:
            queryset = College.objects.all()
        serializer_class = CollegeSerializer(queryset,many=True)
        return Response(serializer_class.data)
    elif(request.method == 'POST'):
        serilizer=CollegeSerializer(data=request.data)
        if serilizer.is_valid():
            serilizer.save()
            return Response(serilizer.data,status=status.HTTP_201_CREATED)
        return Response(serilizer.errors,status=status.HTTP_400_BAD_REQUEST)
    elif(request.method == 'DELETE'):
        if(kwargs):
            College.objects.all().get(id=kwargs['id']).delete()
        return Response(status=status.HTTP_400_BAD_REQUEST)
    elif(request.method == 'PUT'):
        if(kwargs):
            college=College.objects.all().get(id=kwargs['id'])
            serilizer=CollegeSerializer(college,data=request.data)
            if serilizer.is_valid():
                serilizer.save()
                return Response(serilizer.data, status=status.HTTP_201_CREATED)
            return Response(serilizer.errors, status=status.HTTP_400_BAD_REQUEST)
        return  Response(status=status.HTTP_400_BAD_REQUEST)