import numpy as np
import matplotlib.pyplot as plt

#  Euler Theorem
#  exp(-j*2*pi*f*t)= cos(2*pi*f*t)-j*sin(2*pi*f*t)


# when T=0.5
print("For T=0.5 \n\n")

t1=np.linspace(0,0.5,500)
xt1=np.cos(18*np.pi*t1)+np.cos(20*np.pi*t1)


E1=[]
for f in range(0,26):
    reX  = xt1*(np.cos(2*np.pi*f*t1))
    imgX = -1*xt1*(np.sin(2 * np.pi*f*t1))

    reXf = np.trapz(reX,t1)
    imgXf= np.trapz(imgX,t1)

    E1.append((reXf)*(reXf) + (imgXf)*(imgXf))
    print("X1(",f,") = ",reXf," + j",imgXf)

scale1= 1/max(E1)

E1linear=[]
E1dB=[]

for i in range(0,26):
    E1linear.append(scale1*E1[i])
    E1dB.append(20*np.log10(E1linear[i]))

plt.plot(E1linear,"b")
plt.title("ESD for T=0.5")
plt.xlabel("f(hz)")
plt.ylabel("Xf(1/hz)")
plt.show()

plt.plot(E1dB,"r")
plt.title("ESD for T=0.5 in dB scale")
plt.xlabel("f(hz)")
plt.ylabel("Xf(dB)")
plt.show()
print("\n\n")

###########################################
# when T=1
print("For T=1 \n")

t2=np.linspace(0,1,500)
xt2=np.cos(18*np.pi*t2)+np.cos(20*np.pi*t2)


E2=[]
for f in range(0,26):
    reX  = xt2*(np.cos(2*np.pi*f*t2))
    imgX = -1*xt2*(np.sin(2 * np.pi*f*t2))

    reXf = np.trapz(reX,t2)
    imgXf= np.trapz(imgX,t2)

    E2.append((reXf)*(reXf) + (imgXf)*(imgXf))
    print("X2(",f,") = ",reXf," + j",imgXf)


scale2= 1/max(E2)

E2linear=[]
E2dB=[]

for i in range(0,26):
    E2linear.append(scale2*E2[i])
    E2dB.append(20*np.log10(E2linear[i]))

plt.plot(E2linear,"b")
plt.title("ESD for T=1")
plt.xlabel("f(hz)")
plt.ylabel("Xf(1/hz)")
plt.show()

plt.plot(E2dB,"r")
plt.title("ESD for T=1 in dB scale")
plt.xlabel("f(hz)")
plt.ylabel("Xf(dB)")
plt.show()
print("\n\n")

##################################################
# when T=1.5
print("For T=1.5 \n")

t3=np.linspace(0,1.5,500)
xt3=np.cos(18*np.pi*t3)+np.cos(20*np.pi*t3)


E3=[]
for f in range(0,26):
    reX  = xt3*(np.cos(2*np.pi*f*t3))
    imgX = -1*xt3*(np.sin(2 * np.pi*f*t3))

    reXf = np.trapz(reX,t3)
    imgXf= np.trapz(imgX,t3)

    E3.append((reXf)*(reXf) + (imgXf)*(imgXf))
    print("X3(",f,") = ",reXf," + j",imgXf)


scale3= 1/max(E3)

E3linear=[]
E3dB=[]

for i in range(0,26):
    E3linear.append(scale3*E3[i])
    E3dB.append(20*np.log10(E3linear[i]))

plt.plot(E3linear,"b")
plt.title("ESD for T=1.5")
plt.xlabel("f(hz)")
plt.ylabel("Xf(1/hz)")
plt.show()

plt.plot(E3dB,"r")
plt.title("ESD for T=1.5 in dB scale")
plt.xlabel("f(hz)")
plt.ylabel("Xf(dB)")
plt.show()
print("\n\n")

###########################################
# when T=2
print("For T=2 \n")

t4=np.linspace(0,2,500)
xt4=np.cos(18*np.pi*t4)+np.cos(20*np.pi*t4)


E4=[]
for f in range(0,26):
    reX  = xt4*(np.cos(2*np.pi*f*t4))
    imgX = -1*xt4*(np.sin(2 * np.pi*f*t4))

    reXf = np.trapz(reX,t4)
    imgXf= np.trapz(imgX,t4)

    E4.append((reXf)*(reXf) + (imgXf)*(imgXf))
    print("X4(",f,") = ",reXf," + j",imgXf)


scale4= 1/max(E4)

E4linear=[]
E4dB=[]

for i in range(0,26):
    E4linear.append(scale3*E4[i])
    E4dB.append(20*np.log10(E4linear[i]))

plt.plot(E4linear,"b")
plt.title("ESD for T=2")
plt.xlabel("f(hz)")
plt.ylabel("Xf(1/hz)")
plt.show()

plt.plot(E4dB,"r")
plt.title("ESD for T=2 in dB scale")
plt.xlabel("f(hz)")
plt.ylabel("Xf(dB)")
plt.show()
print("\n\n")