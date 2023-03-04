import numpy as np
import time


#Part1
#Euler's Theorem
#exp(-j*2*pi*k*n/N)=cos(2*pi*k*n/N)-jsin(2*pi*k*n/N)

print("Part 1 \n")
Ts=0.01
N=8

for k in range(0,N):
    reXk=0
    imgXk=0

    for n in range(0,N):
        xn = ((n * Ts) ** 2) + 1
        reXk =reXk+ xn*(np.cos(2*np.pi*k*n/N))
        imgXk =imgXk-1*xn*(np.sin(2*np.pi*k*n/N))

    print("X(",k,") = ",reXk," + j",imgXk)

print("\n")

#Part 2
print("Part 2 \n")
n=np.arange(0,N,1)
xn = ((n * Ts) ** 2) + 1
Xk=np.fft.fft(xn)
print(Xk,"\n \n This result is same to the  result obtained in part 1")



#Part 3
print("\n Part 3")
print("Manual calculation: ")

#N=8
N1=8
start1=time.time()
for i in range(1000):
    for k in range(0, N1):
        reXk = 0
        imgXk = 0

        for n in range(0, N1):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N1))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N1))
elapsed1=time.time()-start1
print("time taken when N= 8 : ",elapsed1/1000)

#N=16
N2=16
start2=time.time()
for i in range(1000):
    for k in range(0, N2):
        reXk = 0
        imgXk = 0

        for n in range(0, N2):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N2))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N2))
elapsed2=time.time()-start2
print("time taken when N= 16 : ",elapsed2/1000)

#N=32
N3=32
start3=time.time()
for i in range(100):
    for k in range(0, N3):
        reXk = 0
        imgXk = 0

        for n in range(0, N3):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N3))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N3))
elapsed3=time.time()-start3
print("time taken when N= 32 : ",elapsed3/100)


#N=64
N4=64
start4=time.time()
for i in range(100):
    for k in range(0, N4):
        reXk = 0
        imgXk = 0

        for n in range(0, N4):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N4))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N4))
elapsed4=time.time()-start4
print("time taken when N= 64 : ",elapsed4/100)

#N=128
N5=128
start5=time.time()
for i in range(10):
    for k in range(0, N5):
        reXk = 0
        imgXk = 0

        for n in range(0, N5):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N5))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N5))
elapsed5=time.time()-start5
print("time taken when N= 128 : ",elapsed5/10)

#N=256
N6=256
start6=time.time()
for i in range(10):
    for k in range(0, N6):
        reXk = 0
        imgXk = 0

        for n in range(0, N6):
            xn = ((n * Ts) ** 2) + 1
            reXk = reXk + xn * (np.cos(2 * np.pi * k * n / N6))
            imgXk = imgXk - 1 * xn * (np.sin(2 * np.pi * k * n / N6))
elapsed6=time.time()-start6
print("time taken when N= 256 : ",elapsed6/10 ,"\n\n")


#########################################################
print("calculation using np.fft.fft() function: \n\n")

#N=8
n=np.arange(0,N1,1)
xn = ((n * Ts) ** 2) + 1
start7=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed7=time.time()-start7
print("time taken when N=8:  ",elapsed7/10000)

#N=16
n=np.arange(0,N2,1)
xn = ((n * Ts) ** 2) + 1
start8=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed8=time.time()-start8
print("time taken when N=16:  ",elapsed8/10000)

#N=32
n=np.arange(0,N3,1)
xn = ((n * Ts) ** 2) + 1
start9=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed9=time.time()-start9
print("time taken when N=32:  ",elapsed9/10000)

#N=64
n=np.arange(0,N4,1)
xn = ((n * Ts) ** 2) + 1
start10=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed10=time.time()-start10
print("time taken when N=64:  ",elapsed10/10000)

#N=128
n=np.arange(0,N5,1)
xn = ((n * Ts) ** 2) + 1
start11=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed11=time.time()-start11
print("time taken when N=128:  ",elapsed11/10000)

#N=256
n=np.arange(0,N6,1)
xn = ((n * Ts) ** 2) + 1
start12=time.time()
for i in range(0,10000):
    Xk = np.fft.fft(xn)
elapsed12=time.time()-start12
print("time taken when N=256:  ",elapsed12/10000,"\n\n")

print("Observation:  time taken for np.fft.fft() function is very low when comparing with manual DFT calculation in python")
