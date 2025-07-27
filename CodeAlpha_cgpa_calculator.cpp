#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std ;

class Course
{
    public:

    string name;
    char grade ;
    int credit_hour ;

    Course(string n , char gr, int cr_h)
    {
        name = n ;
        grade = gr ;
        credit_hour = cr_h ;
    }
};

class cgpa_calculation
{
    private: 
    
    vector<Course> courses;

    map<char, double> grade_point_map ;

    public: 
    
    cgpa_calculation()
    {
        grade_point_map = {
            {'A', 4.0}, {'B', 3.0}, {'C', 2.0}, {'D', 1.0}, {'F' , 0.0}
        };
    }

    void add_Course(const Course& course)
    {
        courses.push_back(course);
    }

    double calculate_cgpa()
    {
        double total_point = 0 ;
        int total_credits =  0;

        for(const Course& c : courses)
        {
            if(grade_point_map.find(c.grade) == grade_point_map.end())
            {
               cerr <<"Invalid grade detected for " << c.name<< endl ;
               continue ; 
            }

            total_point += grade_point_map[c.grade] *c.credit_hour ;
            total_credits += c.credit_hour ;
        }   

        return (total_credits > 0) ? total_point / total_credits : 0.0;
    
    }

    void display_course()
    {
      
        cout << "\nCourse Grade :\n";
        cout <<left << setw(20) <<"Course Name " << setw(10)<< "Grade" <<"Credit Hours \n";
        
        for(const Course& c : courses)
        {
            cout << left<< setw(20) <<c.name << setw(10) << c.grade <<c.credit_hour <<endl;
        }  
    }
};

int main()
{

    cgpa_calculation calc;
    int n ;
    
    cout << "Enter the number of courses : \n" ;
    cin >> n ;

    for(int i = 0 ; i < n ; ++i)
    {
        string name ;
        char grade ;
        int credit ;

        cout << "\nCourse " << i+1 << " : \n" ;
        cout << "Course name : " ;
        cin.ignore();
        getline(cin , name);
        
        cout << "Grade (A/B/C/D/f) : " ;
        cin >> grade ;
        
        cout << "Credit hour : ";
        cin >> credit ;

        calc.add_Course(Course(name, toupper(grade), credit));
    }

    calc.display_course();
    
    cout << fixed << setprecision(2) ;
    cout << "\n Your GPA is : " << calc.calculate_cgpa() << endl ;
    
    
    return 0;

}

