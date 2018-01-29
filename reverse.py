

a=open('/home/s/reverse','r').read().encode('hex')[::-1].decode('hex') #reverse is the image file name
output=open('output','w').write(a)
