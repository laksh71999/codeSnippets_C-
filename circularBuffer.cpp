#include <iostream>

#define BufferSize 10

using namespace std;

int32_t circularBuffer[BufferSize];
int32_t circularBufftail = 0;
int32_t circularBuffhead = 0;

void circularbuffPush(int32_t value) {
    if ((circularBufftail + 1) % BufferSize == circularBuffhead) {
        cout<<"Buffer Full\n";
        return;
    }

    circularBuffer[circularBufftail] = value;
    circularBufftail = (circularBufftail + 1) % BufferSize;
}

int32_t circularbuffPop() {
    if (circularBuffhead == circularBufftail) {
        cout<<"Buffer Empty\n";
        return -1;
    }

    int32_t value = circularBuffer[circularBuffhead];
    circularBuffhead = (circularBuffhead + 1) % BufferSize;
    return value;
}

int main(){
    for(int i=0;i<10;i++){
        circularbuffPush(i); //Input - Use circularbuffPush and pass the value to store in it.

        cout<<circularbuffPop()<<"\n";  //Output - Use circularbuffPop
    }
}
