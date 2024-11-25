#include <iostream>
#include <vector>

class Student{
    public:
    static const int max_score = 100;
    static const int min_score = 0;
    int id;
    int classroom_id;
    int final_score = 0;

    void set_up(int input_id, int input_classroom_id, int input_final_score){
        id = id;
        classroom_id = input_classroom_id;
        final_score = input_final_score;
    }

    void assign_score(int score){
        if (score<0||score>100){
            std::cout<<"Invalid Score. Please only enter values between 0 to 100.";
        }
    }
};

class Room{
    public:
    static const int max_students_size = 35;
    std::vector<Student> student_batch;
    int id;

    int get_total_class_score(){
        int summation_of_scores;
        for(int i = 0; i<student_batch.size();i++){
            summation_of_scores += student_batch[i].final_score;
        }

        return summation_of_scores;
    }
};

int max_rooms = 30;

std::vector<Room> create_classrooms(){
    std::vector<Room> classrooms;

    for (int i = 0;i<max_rooms;i++){
        Room classroom;
        classroom.id = i;
        classrooms.push_back(classroom);
    }

    return classrooms;
}

std::vector<Student> create_student_data(){
    std::vector<Student> student_body;

    std::cout<<"Enter student data"<<std::endl;
    std::cout<<"Enter student ID, classroom ID then their final score."<<std::endl;
    std::cout<<"Enter 0 in any fields to stop inputing data."<<std::endl;
    for (int i=0;i<max_rooms*Room::max_students_size;i++){

        std::cout<<"New Student Template Created."<<std::endl;

        int score = 0;
        int class_id = 0;
        int student_id = 0;

        std::cout<<"Student ID : ";
        std::cin>>student_id;
        std::cout<<"Classroom ID : ";
        std::cin>>class_id;
        std::cout<<"Final Score : ";
        std::cin>>score;

        if (!score||!class_id||!student_id){
            int answer;
            std::cout<<"You entered empty data."<<std::endl;
            std::cout<<"You wish to end inputting data here?"<<std::endl;
            std::cout<<"Enter 0 to stop inputting student data or any characters to continue."<<std::endl;
            std::cin>>answer;
            if (answer == 0){
                std::cout<<"Ending inputting of student data"<<std::endl;
                break;
            }
            else{
                std::cout<<"You have selected to continue inputting student data."<<std::endl;
            }
        }
        Student new_student;
        new_student.set_up(student_id, class_id, score);
        student_body.push_back(new_student);
        std::cout<<"Printing score of new student"<<student_body[i].final_score<<std::endl;
        
    }
    return student_body;
}

void assign_rooms(std::vector<Student> &student_body, std::vector<Room> &classrooms){
    for(int i = 0; i <= student_body.size(); i++){
        Student current_student = student_body[i];
        for (int j = 0;j <classrooms.size(); j++){
            Room current_room = classrooms[i];

            if (current_room.student_batch.size() < Room::max_students_size){
                current_room.student_batch.push_back(current_student);
                break;
                
            }
            std::cout<<"Room size"<<current_room.student_batch.size()<<std::endl;

        }
    }
    
}

void print_classroom_scores(std::vector<Room> &classrooms){
    for(int i = 0; i<classrooms.size(); i++){
        Room current_classroom = classrooms[i];
        std::cout<<"Classroom "<< current_classroom.id+1<< " :" << current_classroom.get_total_class_score()<<std::endl;
    }
}




int main(){
    std::vector<Room> computer_lab_rooms = create_classrooms();
    std::vector<Student> student_body = create_student_data();
    assign_rooms(student_body, computer_lab_rooms);
    print_classroom_scores(computer_lab_rooms);


    return 0;
}