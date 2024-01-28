import random 
import time #here we have to do time.function_name() to access function
from time import * #from we can directly access function of time module and we don't have to do time.function_name()\
# print(time)
# import math

import random as r
def mistake_counter(partest,usertest):
    error=0
    for i in range(0,len(partest)):
        try:
            if partest[i] != usertest[i]:
                error=error+1
        except :
            error=error+1
    return error

def speed_time(time_start,time_end,user_input):
    time_delay=time_end - time_start
    time_round_of= round(time_delay,2)
    speed=len(user_input)/time_round_of
    return round(speed)






print("**********Typing__Speed__Calculator**********")
while True:
    ck=input("Ready to test type yes or no :").lower()
    if ck=='yes':
        test=["Taj Mahal is known as a symbol of love. The full name is Mumtaz Mahal was the name of Mughal Emperor Shah Jahan's wife's name. He was a widely known and powerful emperor in his time.", "A quick brown fox jumps over the lazy dog"]
        test1=r.choice(test)
        # print("**********Typing__Speed__Calculator**********")
        print(test1)
        print("")
        time_1=time()
        test_input=input(" Enter: ")
        time_2=time()
        print(f"'Speed' :  {speed_time(time_1,time_2,test_input)} word per second") 
        print(f"Errors_counted: {mistake_counter(test1,test_input)}")




import speedtest
def test_speed():
    st = speedtest.Speedtest()

    download_speed = st.download() / 1_000_000  # Convert to megabits per second
    upload_speed = st.upload() / 1_000_000  # Convert to megabits per second
    ping_speed = st.results.ping

    print(f"Download Speed: {download_speed:.2f} Mbps")
    print(f"Upload Speed: {upload_speed:.2f} Mbps")
    print(f"Ping: {ping_speed} ")

if __name__ == "__main__":
    print("Running Speed Test...")
    test_speed()