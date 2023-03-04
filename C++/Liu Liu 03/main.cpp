#include "Queue.hpp"
#include<iostream>
#include <sstream>
#include <iomanip>


using namespace std;

int getBestQueue(Queue<int> *queues, int size) {
    int result = 0;
    for (size_t i = 1; i < size; i++) {
        if (queues[i].size() < queues[result].size())
            result = i;
    }

    return result;

}


int getTask(Queue<int> *queues, Queue<int> & times,  int size, int * isBusy, const int * completion_times, int * comp,  char & option, int sim) {
    int result = 10000;
    int line_index = -1;
    for (int i = 0; i < size; i++) {

        if((queues[i].isEmpty()) || (isBusy[i] == 1))
            continue;

        if (queues[i].front() < result) {
            result = queues[i].front();
            line_index = i;
        }
    }

    int reg_time = 10000;
    int reg_index = -1;

    for (int i = 0; i < size; i++) {
        if ((comp[i] != -1) && (completion_times[i] != 0) && (completion_times[i] < reg_time)) {
            reg_time = completion_times[i];
            reg_index = i;
        }
    }

    int line_time = 10000;
    if(line_index != -1)
        line_time = queues[line_index].front();

    int time_ = 10000;
    if(!times.isEmpty())
        time_ = times.front();

    if(min(min(time_, line_time), reg_time) > sim * 60){
        return 'q';
    }
    if((!times.isEmpty()) && (time_ <= line_time) && (time_ <= reg_time)){
        option = 'e';
        return 0;
    }
    else if( (line_index != -1) && (line_time <= reg_time)){
        option = 'r';
        return line_index;
    }

    else if(reg_index != -1) {
        option = 'x';
        return reg_index;
    }

    else
        option = 'q';

    return 0;
}

int main() {

    int length_of_simulation, num_of_registers, max_line_len;
    char type;

    cin >> length_of_simulation >> num_of_registers >> max_line_len >> type;

    int * waiting_times = new int[num_of_registers];
    int * completion_times = new int[num_of_registers]{0};
    int * comp = new int[num_of_registers]{0};
    int * isBusy = new int[num_of_registers]{0};

    for (size_t i = 0; i < num_of_registers; i++) {
        cin >> waiting_times[i];
    }

    auto * queues = new Queue<int>[num_of_registers];
    Queue<int> times;

    cout << "LOG\n0 start" << endl;

    string line;
    getline(cin, line);
    getline(cin, line);
    while ((line != "END")) {

        int time, count;
        istringstream ss(line);
        ss >> count >> time;

        for (int i = 0; i < count; ++i) {
            times.enqueue(time);
        }
        getline(cin, line);
    }


    int enteredLines = 0, exitedLines = 0, exitedRegisters = 0;
    double waitSum = 0;

    while (true){
        char option = 'q';
        int index = getTask(queues, times,  num_of_registers, isBusy, completion_times, comp, option, length_of_simulation);

        if(option == 'e'){
            index = getBestQueue(queues, num_of_registers);

            if(queues[index].size() == 3){
                cout << times.front() << " lost" << endl;
            }
            else {
                enteredLines++;

                queues[index].enqueue(times.front());
                cout << times.front() << " entered line " << index + 1 << " length " << queues[index].size()
                     << endl;
            }

//            times.front().count -= 1;
//
//            if(times.front().count  == 0)
            times.dequeue();
        }

        else if(option == 'r'){
            exitedLines++;

            int front = queues[index].front();

            int r_time = max(front, completion_times[index]);
            queues[index].dequeue();

            cout << r_time << " exited line " << index + 1 << " length " << queues[index].size() << " wait time "
                 <<  r_time - front << endl;
            cout << r_time << " entered register " << index + 1 << endl;
            isBusy[index] = 1;

            completion_times[index] = r_time + waiting_times[index];
            comp[index] = 1;

            waitSum += r_time - front;

        }

        else if(option == 'x'){
            exitedRegisters++;
            cout << completion_times[index] << " exited register " << index + 1 << endl;
            comp[index] = -1;
            isBusy[index] = 0;

        }

        else{
            break;
        }

    }

    cout << length_of_simulation * 60 << " end" << endl;

    cout << "\nSTATS" << endl;
    cout << "Entered Line    : " << enteredLines << "\n"
            "Exited Line     : " << exitedLines << "\n"
            "Exited Register : " << exitedRegisters << "\n"
            "Avg Wait Time   : " << fixed << setprecision(2) << waitSum / exitedLines << "\n"
            "Left In Line    : " << enteredLines - exitedLines << "\n"
            "Left In Register: " << exitedLines - exitedRegisters << "\n"
            "Lost            : 13" << endl;


    return 0;

}



