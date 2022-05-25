#pragma once
#include <string>

// Number of characters cin.ignore pulls from the buffer to disgard
const int numCharsToDisgardCinIgnore = 256;

// Master list of all employees.
// Handles the mentorships between employees as well as keeps record of each employees name and level.
class ListOfEmployees {

    private:

        struct employee {

            std::string name;
            int level;

            employee * next;
            employee * prev;

            employee * mentor;
            employee * mentee;
        };

        employee * front;
        employee * back;

        int size;


        employee * create(std::string name, int level);
        employee * lookup (std::string n);
        void deallocate();

        bool insert (employee * newE);
        bool remove (employee * toDelete);

        bool initializeMentorship(employee * mentor, employee * mentee);
        bool removeMentorship(employee * mentor, employee * mentee);
        void mentorshipInfo(employee * e);

        void printLevel(int l);
        void printAll();
        

    public:

    ListOfEmployees ();
    ~ListOfEmployees ();

    
    bool hire (std::string name, int level);
    bool fire (std::string name);
    bool changeLevel(std::string name, int newLevel);
    int getEmployeeLevel(std::string name);
    
    bool createMentorship(std::string mentor, std::string mentee);
    bool endMentorship(std::string mentor, std::string mentee);
    void getMentorshipInfo(std::string name);
    void printAllMentorships();

    void printL(int l);
    void printA();

    friend bool confirmMentorship (ListOfEmployees::employee * e);



};


// List of employees at a given level
// There are four instances of this class, one for each level.
// Each employee will be in two lists at any given time, the master list and their level list.
class ListOfLevel {

        private:

            struct employee {

                std::string name;
                int level;

                employee * next;
                employee * prev;
            };

            employee * front;
            employee * back;

            int size;


            employee * create(std::string name, int level);
            employee * lookup (std::string n);
            void deallocate();

            bool insert (employee * newE);
            bool remove (employee * toDelete);

            void printAll();

        public:

        ListOfLevel ();
        ~ListOfLevel ();
        bool hire (std::string name, int level);
        bool fire (std::string name);
        void printA();
};

