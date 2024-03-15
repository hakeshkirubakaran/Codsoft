#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct taskList{
    string task;
    string status;
};

vector<taskList> tasks;

void addTask(){
    cout << "Enter task description: ";
    string dcrp;
    getline(cin, dcrp);
    tasks.push_back({dcrp, "pending"});
}

void dispTask(){
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout<<i+1<<"."<<tasks[i].task << " ("<<tasks[i].status<<")"<<endl;
    }
}

void markComplete(){
    cout << "Enter task number to mark as complete: ";
    int num;
    cin >> num;
    tasks[num - 1].status = "completed";
}

void Remove(){
    cout << "Enter task number to remove: ";
    int num;
    cin >> num;
    tasks.erase(tasks.begin() + num - 1);
}

void saveTasks(){
    ofstream outFile("tasks.txt");
    for (auto & task : tasks) {
        outFile << task.task << "," << task.status << "\n";
    }
    outFile.close();
}

void loadTasks(){
    ifstream inFile("tasks.txt");
    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(",");
        string task = line.substr(0, pos);
        string status = line.substr(pos + 1);
        tasks.push_back({task, status});
    }
    inFile.close();
}

int main(){
    loadTasks();
    while(true){
        cout << "\n\n1. Add task\n2. View tasks\n3. Mark task as completed\n4. Remove task\n5. Save tasks\n6. Exit\n";
        int choice;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            system("CLS");
            addTask();
        } else if(choice == 2){
            system("CLS");
            dispTask();
        } else if(choice == 3){
            system("CLS");
            markComplete();
        } else if(choice == 4){
            system("CLS");
            Remove();
        } else if(choice == 5){
            system("CLS");
            saveTasks();
        } else if(choice == 6){
            break;
        }
    }
    return 0;
}
