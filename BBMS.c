#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class secure
{
private:
    string pass_donor = "Donor_rec@2021";
    string pass_patient = "Patient_rec@2021";

public:
    int enter_donor_pass(string pw)
    {
        if (pass_donor.compare(pw) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int enter_patient_pass(string pw)
    {
        if (pass_patient.compare(pw) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
class donor_rec
{

public:
    char name[30], gender[10], Blood_g[10], email[20], d_o_BD[10];
    long long int mobile_number;
    int age;
    int packets;
    void display_donor();
    void store_data();
};
void donor_rec::display_donor()
{
    ifstream donor_file;
    donor_file.open("Donor_Records.txt", ios::in);
    donor_rec obj1;
    donor_file.read((char *)&obj1, sizeof(obj1));
    if (!donor_file)
    {
        cout << "No Data available for Donor" << endl;
    }
    else
    {
        while (!donor_file.eof())
        {

            cout << "------------------------------------------------------" << endl;
            cout << "Name : " << obj1.name << endl
                 << "Age : " << obj1.age << endl
                 << "Gender : " << obj1.gender << endl
                 << "Mobile Number : " << obj1.mobile_number << endl
                 << "Email Address : " << obj1.email << endl
                 << "Date Of Blood Donation : " << obj1.d_o_BD << endl
                 << "Blood Group : " << obj1.Blood_g << endl
                 << "Number of packets : " << obj1.packets << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;

            donor_file.read((char *)&obj1, sizeof(obj1));
        }
    }
}

void donor_rec::store_data()
{
    ofstream donor_file;
    donor_file.open("Donor_Records.txt", ios::app);
    donor_file.write((char *)this, sizeof(*this));
    donor_file.close();
}

class patient_rec
{
public:
    char name[30], gender[10], Blood_g[10], email[20], d_o_BD[10];
    long long int mobile_number;
    int age;
    int packets;
    void display_patient();
    void store_data();
    void donor_availability();
    string converttostring(char *a, int size);
};

void patient_rec::display_patient()
{
    ifstream patient_file;
    patient_file.open("Patient_Records.txt", ios::in);
    patient_rec obj2;
    patient_file.read((char *)&obj2, sizeof(obj2));
    if (!patient_file)
    {
        cout << "No Data available for Patient" << endl;
    }
    else
    {
        while (!patient_file.eof())
        {

            cout << "------------------------------------------------------" << endl;
            cout << "Name : " << obj2.name << endl
                 << "Age : " << obj2.age << endl
                 << "Gender : " << obj2.gender << endl
                 << "Mobile Number : " << obj2.mobile_number << endl
                 << "Email Address : " << obj2.email << endl
                 << "Date Of Blood Donation : " << obj2.d_o_BD << endl
                 << "Blood Group : " << obj2.Blood_g << endl
                 << "Number of packets : " << obj2.packets << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;

            patient_file.read((char *)&obj2, sizeof(obj2));
        }
    }
}

void patient_rec::donor_availability()
{
    string check, compare;
    check = converttostring(Blood_g, 6);
    ifstream donor_file;
    donor_file.open("Donor_Records.txt", ios::in);
    donor_rec obj1;
    donor_file.read((char *)&obj1, sizeof(obj1));
    if (!donor_file)
    {
        cout << "No Data available for Donor" << endl;
    }
    else
    {
        cout<<endl;
        cout << "These are the records of donor who donated " << check << " Blood Group. This records might helpful to you." << endl << endl;
        while (!donor_file.eof())
        {
            
            compare = converttostring(obj1.Blood_g, 6);
            if (compare == check)
            {
                cout << "------------------------------------------------------" << endl;
            cout << "Name : " << obj1.name << endl
                 << "Age : " << obj1.age << endl
                 << "Gender : " << obj1.gender << endl
                 << "Mobile Number : " << obj1.mobile_number << endl
                 << "Email Address : " << obj1.email << endl
                 << "Date Of Blood Donation : " << obj1.d_o_BD << endl
                 << "Blood Group : " << obj1.Blood_g << endl
                 << "Number of packets : " << obj1.packets << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;
            }
            else
            {
                cout<<"We cannot find donors who had donated "<<check<<" Blood Group."<<endl;
            }
            donor_file.read((char *)&obj1, sizeof(obj1));
        }
    }
}

string patient_rec::converttostring(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

void patient_rec::store_data()
{
    ofstream patient_file;
    patient_file.open("Patient_Records.txt", ios::app);
    patient_file.write((char *)this, sizeof(*this));
    patient_file.close();
}

class admin
{
private:
    string password = "Admin_rec@2021";
    int i;

protected:
    int size, type[8] = {0, 0, 0, 0, 0, 0, 0, 0};

public:
    void remove_data()
    {
        remove("Admin_Records.txt");
        if (remove("Admin_Records.txt") == 0)
            cout << "Deleted Successfully" << endl;
    }
    void store_data()
    {
        ofstream admin_file;
        admin_file.open("Admin_Records.txt", ios::app);
        admin_file.write((char *)this, sizeof(*this));
        admin_file.close();
    }
    void revive()
    {
        int i;
        ifstream admin_file;
        admin_file.open("Admin_Records.txt", ios::in);
        admin obj;
        admin_file.read((char *)&obj, sizeof(obj));
        for (i = 0; i < 8; i++)
        {
            type[i] = obj.type[i];
        }
    }
    void admin_display()
    {
        ifstream admin_file;
        admin_file.open("Admin_Records.txt", ios::in);
        admin obj;
        admin_file.read((char *)&obj, sizeof(obj));
        cout << "A +ve: " << obj.type[0] << endl;
        cout << "O +ve: " << obj.type[1] << endl;
        cout << "B +ve: " << obj.type[2] << endl;
        cout << "AB +ve: " << obj.type[3] << endl;
        cout << "A -ve: " << obj.type[4] << endl;
        cout << "O -ve: " << obj.type[5] << endl;
        cout << "B -ve: " << obj.type[6] << endl;
        cout << "AB -ve: " << obj.type[7] << endl;
        cout << endl;
    }
    void all_blood_type(string pw)
    {
        if (password.compare(pw) == 0)
        {
            cout << "Welcome Admin!" << endl;
            cout << endl;
            cout << "Available packets" << endl;
            cout << "A +ve: " << type[0] << endl;
            cout << "O +ve: " << type[1] << endl;
            cout << "B +ve: " << type[2] << endl;
            cout << "AB +ve: " << type[3] << endl;
            cout << "A -ve: " << type[4] << endl;
            cout << "O -ve: " << type[5] << endl;
            cout << "B -ve: " << type[6] << endl;
            cout << "AB -ve: " << type[7] << endl;
            cout << endl;
        }
        else
        {
            cout << "Incorrect password!" << endl;
            cout << endl;
        }
    }
    void blood_store(int bg_type, int packets)
    {
        type[bg_type] = type[bg_type] + packets;
    }

    int blood_available(int bg_type, int packets)
    {
        if (bg_type == 0)
        {
            i = 1;
            cout << "A +ve:" << type[0] << endl;
            cout << "A -ve:" << type[4] << endl;
            cout << "O +ve:" << type[1] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[0] > 0)
            {
                if (type[0] <= packets)
                {
                    cout << type[0] << " packet(s) of A +ve blood group is/are available." << endl;
                    type[0] = 0;
                }
                else
                {
                    type[0] = type[0] - packets;
                }
            }
            else if (type[4] > 0)
            {
                if (type[4] <= packets)
                {
                    cout << type[4] << " packet(s) of A -ve blood group is/are available." << endl;
                    type[4] = 0;
                }
                else
                {
                    type[4] = type[4] - packets;
                }
            }
            else if (type[1] > 0)
            {
                if (type[1] <= packets)
                {
                    cout << type[1] << " packet(s) of O +ve blood group is/are available." << endl;
                    type[1] = 0;
                }
                else
                {
                    type[1] = type[1] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 1)
        {
            i = 1;
            cout << "O +ve:" << type[1] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[1] > 0)
            {
                if (type[1] <= packets)
                {
                    cout << type[1] << " packet(s) of O +ve blood group is/are available." << endl;
                    type[1] = 0;
                }
                else
                {
                    type[1] = type[1] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 2)
        {
            i = 1;
            cout << "B +ve:" << type[2] << endl;
            cout << "B -ve:" << type[6] << endl;
            cout << "O +ve:" << type[1] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[2] > 0)
            {
                if (type[2] <= packets)
                {
                    cout << type[2] << " packet(s) of B +ve blood group is/are available." << endl;
                    type[2] = 0;
                }
                else
                {
                    type[2] = type[2] - packets;
                }
            }
            else if (type[6] > 0)
            {
                if (type[6] <= packets)
                {
                    cout << type[6] << " packet(s) of B -ve blood group is/are available." << endl;
                    type[6] = 0;
                }
                else
                {
                    type[6] = type[6] - packets;
                }
            }

            else if (type[1] > 0)
            {
                if (type[1] <= packets)
                {
                    cout << type[1] << " packet(s) of O +ve blood group is/are available." << endl;
                    type[1] = 0;
                }
                else
                {
                    type[1] = type[1] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 3)
        {
            i = 1;
            cout << "A +ve:" << type[0] << endl;
            cout << "A -ve:" << type[4] << endl;
            cout << "B +ve:" << type[2] << endl;
            cout << "B -ve:" << type[6] << endl;
            cout << "AB +ve:" << type[3] << endl;
            cout << "AB -ve:" << type[7] << endl;
            cout << "O +ve:" << type[1] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[3] > 0)
            {
                if (type[3] <= packets)
                {
                    cout << type[3] << " packet(s) of AB +ve blood group is/are available." << endl;
                    type[3] = 0;
                }
                else
                {
                    type[3] = type[3] - packets;
                }
            }
            else if (type[0] > 0)
            {
                if (type[0] <= packets)
                {
                    cout << type[0] << " packet(s) of A +ve blood group is/are available." << endl;
                    type[0] = 0;
                }
                else
                {
                    type[0] = type[0] - packets;
                }
            }
            else if (type[4] > 0)
            {
                if (type[4] <= packets)
                {
                    cout << type[1] << " packet*(s) of A -ve blood group is/are available." << endl;
                    type[4] = 0;
                }
                else
                {
                    type[4] = type[4] - packets;
                }
            }
            else if (type[2] > 0)
            {
                if (type[2] <= packets)
                {
                    cout << type[2] << " packet(s) of B +ve blood group is/are available." << endl;
                    type[2] = 0;
                }
                else
                {
                    type[2] = type[2] - packets;
                }
            }
            else if (type[6] > 0)
            {
                if (type[6] <= packets)
                {
                    cout << type[6] << " packet(s) of B -ve blood group is/are available." << endl;
                    type[6] = 0;
                }
                else
                {
                    type[6] = type[6] - packets;
                }
            }
            else if (type[7] > 0)
            {
                if (type[7] <= packets)
                {
                    cout << type[7] << " packet(s) of AB -ve blood group is/are available." << endl;
                    type[7] = 0;
                }
                else
                {
                    type[7] = type[7] - packets;
                }
            }
            else if (type[1] > 0)
            {
                if (type[1] <= packets)
                {
                    cout << type[1] << " packet(s) of O +ve blood group is/are available." << endl;
                    type[1] = 0;
                }
                else
                {
                    type[1] = type[1] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }
        else if (bg_type == 4)
        {
            i = 1;
            cout << "A -ve:" << type[4] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[4] > 0)
            {
                if (type[4] <= packets)
                {
                    cout << type[1] << " packet(s) of A -ve blood group is/are available." << endl;
                    type[4] = 0;
                }
                else
                {
                    type[4] = type[4] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }

            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 5)
        {
            i = 1;
            cout << "B -ve:" << type[6] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else if (type[6] > 0)
            {
                if (type[6] <= packets)
                {
                    cout << type[6] << " packet(s) of B -ve blood group is/are available." << endl;
                    type[6] = 0;
                }
                else
                {
                    type[6] = type[6] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 6)
        {
            i = 1;
            cout << "A +ve:" << type[0] << endl;
            cout << "A -ve:" << type[4] << endl;
            cout << "B +ve:" << type[2] << endl;
            cout << "B -ve:" << type[6] << endl;
            cout << "AB +ve:" << type[3] << endl;
            cout << "AB -ve:" << type[7] << endl;
            cout << "O +ve:" << type[1] << endl;
            cout << "O -ve:" << type[5] << endl;

            if (type[6] > 0)
            {
                if (type[6] <= packets)
                {
                    cout << type[6] << " packet(s) of B -ve blood group is/are available." << endl;
                    type[6] = 0;
                }
                else
                {
                    type[6] = type[6] - packets;
                }
            }
            else if (type[0] > 0)
            {
                if (type[0] <= packets)
                {
                    cout << type[0] << " packet(s) of A +ve blood group is/are available." << endl;
                    type[0] = 0;
                }
                else
                {
                    type[0] = type[0] - packets;
                }
            }
            else if (type[4] > 0)
            {
                if (type[4] <= packets)
                {
                    cout << type[1] << " packet(s) of A -ve blood group is/are available." << endl;
                    type[4] = 0;
                }
                else
                {
                    type[4] = type[4] - packets;
                }
            }
            else if (type[2] > 0)
            {
                if (type[2] <= packets)
                {
                    cout << type[2] << " packet(s) of B +ve blood group is/are available." << endl;
                    type[2] = 0;
                }
                else
                {
                    type[2] = type[2] - packets;
                }
            }
            else if (type[3] > 0)
            {
                if (type[3] <= packets)
                {
                    cout << type[3] << " packet(s) of AB +ve blood group is/are available." << endl;
                    type[3] = 0;
                }
                else
                {
                    type[3] = type[3] - packets;
                }
            }
            else if (type[7] > 0)
            {
                if (type[7] <= packets)
                {
                    cout << type[7] << " packet(s) of AB -ve blood group is/are available." << endl;
                    type[7] = 0;
                }
                else
                {
                    type[7] = type[7] - packets;
                }
            }
            else if (type[1] > 0)
            {
                if (type[1] <= packets)
                {
                    cout << type[1] << " packet(s) of O +ve blood group is/are available." << endl;
                    type[1] = 0;
                }
                else
                {
                    type[1] = type[1] - packets;
                }
            }
            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }
            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }

        else if (bg_type == 7)
        {
            i = 1;
            cout << "A -ve:" << type[4] << endl;
            cout << "B -ve:" << type[6] << endl;
            cout << "O -ve:" << type[5] << endl;
            cout << "AB -ve:" << type[7] << endl;

            if (type[7] > 0)
            {
                if (type[7] <= packets)
                {
                    cout << type[7] << " packet(s) of AB -ve blood group is/are available." << endl;
                    type[7] = 0;
                }
                else
                {
                    type[7] = type[7] - packets;
                }
            }

            else if (type[4] > 0)
            {
                if (type[4] <= packets)
                {
                    cout << type[4] << " packet(s) of A -ve blood group is/are available." << endl;
                    type[4] = 0;
                }
                else
                {
                    type[4] = type[4] - packets;
                }
            }

            else if (type[6] > 0)
            {
                if (type[6] <= packets)
                {
                    cout << type[6] << " packet(s) of B -ve blood group is/are available." << endl;
                    type[6] = 0;
                }
                else
                {
                    type[6] = type[6] - packets;
                }
            }

            else if (type[5] > 0)
            {
                if (type[5] <= packets)
                {
                    cout << type[5] << " packet(s) of O -ve blood group is/are available." << endl;
                    type[5] = 0;
                }
                else
                {
                    type[5] = type[5] - packets;
                }
            }

            else
            {
                i = 0;
                cout << "Compatible blood group not available";
            }
        }
        return i;
    }
};

int main()
{

    donor_rec obj;
    patient_rec objp;
    admin A;
    secure objs;
    A.revive();
    int choice, bg_type, packets, age, input, pulse_rate, flag, i;
    long long int mn;
    float weigth, haemoglobin, syspressure, diapressure;
    char response;
    char na[30], gen[10], ea[20], dobd[10];
    string pw, r(100, '='), bg_proto;

    cout << "                 ==============================  ==============================" << endl;
    cout << "==============================   WELCOME TO THE BLOOD BANK  ==================================" << endl;
    cout << "                 ==============================  ==============================" << endl;
    do
    {
        cout << r << endl;
        cout << "Enter: " << endl
             << "1: If you are a admin" << endl
             << "2: If you are a donor" << endl
             << "3: If you are a patient" << endl
             << "4: Display records of Donor" << endl
             << "5: Display records of Patient" << endl
             << "0: if you want to exit" << endl;
        cout << endl;
        cout << r << endl;
        cout << "Choice : ";
        cin >> choice;
        cout << r << endl;
        switch (choice)
        {
        case 1:
            cout << endl;
            cout << "Enter Password: ";
            cin >> pw;
            A.all_blood_type(pw);
            break;
        case 2:
            cout << endl;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter Weight(Kg): ";
            cin >> weigth;
            cout << "Enter Pulse rate: ";
            cin >> pulse_rate;
            cout << "Enter Haemoglobin(g/L): ";
            cin >> haemoglobin;
            cout << "Enter systolic blood pressure: ";
            cin >> syspressure;
            cout << "Enter diastolic blood pressure: ";
            cin >> diapressure;
            cout << endl;
            if ((age > 18 && age < 65) && weigth > 50 && (pulse_rate > 50 && pulse_rate < 100) && haemoglobin > 12.5 && (syspressure > 90 && syspressure < 180) && (diapressure > 50 && diapressure < 100))
            {
                cout << "============================== "
                     << " Welcome Donor ! "
                     << " ============================== " << endl;
                cout << endl;
                cin.clear();
                cin.sync();
                cout << "Enter Name: ";
                cin.clear();
                cin.sync();
                cin.getline(na, 30);
                cin.clear();
                cin.sync();
                cout << "Enter Mobile number: ";
                cin >> mn;
                cout << "Enter Email address: ";
                cin.clear();
                cin.sync();
                cin.getline(ea, 20);
                cout << "Enter date of Blood Donation: ";
                cin.clear();
                cin.sync();
                cin.getline(dobd, 10);
                cout << "Enter Gender: ";
                cin.getline(gen, 10);
                cout << "Which Blood Group you want to donate: " << endl;
                cout << "0 - A +ve" << endl;
                cout << "1 - O +ve" << endl;
                cout << "2 - B +ve" << endl;
                cout << "3 - AB +ve" << endl;
                cout << "4 - A -ve" << endl;
                cout << "5 - O -ve" << endl;
                cout << "6 - B -ve" << endl;
                cout << "7 - AB -ve" << endl;
                cin.clear();
                cin.sync();
                cout << "Blood Group type: ";
                cin >> bg_type;
                cout << endl;
                if (bg_type == 0)
                {
                    bg_proto = "A +ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 1)
                {
                    bg_proto = "O +ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 2)
                {
                    bg_proto = "B +ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 3)
                {
                    bg_proto = "AB +ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 4)
                {
                    bg_proto = "A -ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 5)
                {
                    bg_proto = "O -ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 6)
                {
                    bg_proto = "B -ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                else if (bg_type == 7)
                {
                    bg_proto = "AB -ve";
                    cout << bg_type << " - " << bg_proto << endl;
                }
                cout << endl;
                int n = bg_proto.length();
                char bg[n + 1];
                strcpy(bg, bg_proto.c_str());
                cin.clear();
                cin.sync();
                cout << "Enter number of packets you want to donate: ";
                cin >> packets;
                string r(195, '=');

                strcpy(obj.name, na);
                strcpy(obj.Blood_g, bg);
                strcpy(obj.gender, gen);
                obj.packets = packets;
                obj.age = age;
                obj.mobile_number = mn;
                strcpy(obj.email, ea);
                strcpy(obj.d_o_BD, dobd);
                obj.store_data();

                A.blood_store(bg_type, packets);
                cout << endl;
                break;
            }
            else
            {
                cout << "You are not eligible for blood donation !";
                cout << endl;
                break;
            }

        case 3:
            cout << "============================== "
                 << "Welcome Patient !"
                 << " ============================== " << endl;
            cin.clear();
            cin.sync();
            cout << "Enter Name: ";
            cin.clear();
            cin.sync();
            cin.getline(na, 30);
            cin.clear();
            cin.sync();
            cout << "Enter age of patient: ";
            cin >> age;
            cin.clear();
            cin.sync();
            cout << "Enter Mobile number: ";
            cin >> mn;
            cout << "Enter Email address: ";
            cin.clear();
            cin.sync();
            cin.getline(ea, 20);
            cout << "Enter date of Blood Transfudion: ";
            cin.clear();
            cin.sync();
            cin.getline(dobd, 10);
            cout << "Enter Gender: ";
            cin.getline(gen, 10);
            cout << endl;
            cout << "Which Blood Group do you want: " << endl;
            cout << "0 - A +ve" << endl;
            cout << "1 - O +ve" << endl;
            cout << "2 - B +ve" << endl;
            cout << "3 - AB +ve" << endl;
            cout << "4 - A -ve" << endl;
            cout << "5 - O -ve" << endl;
            cout << "6 - B -ve" << endl;
            cout << "7 - AB -ve" << endl;
            cout << endl;
            cout << "Blood Group type: ";
            cin >> bg_type;
            if (bg_type == 0)
            {
                bg_proto = "A +ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 1)
            {
                bg_proto = "O +ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 2)
            {
                bg_proto = "B +ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 3)
            {
                bg_proto = "AB +ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 4)
            {
                bg_proto = "A -ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 5)
            {
                bg_proto = "O -ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 6)
            {
                bg_proto = "B -ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            else if (bg_type == 7)
            {
                bg_proto = "AB -ve";
                cout << bg_type << " - " << bg_proto << endl;
            }
            cout << endl;

            char bg_p[6];
            strcpy(bg_p, bg_proto.c_str());
            cout << "Enter number of packets you want: ";
            cin >> packets;

            strcpy(objp.name, na);
            strcpy(objp.Blood_g, bg_p);
            strcpy(objp.gender, gen);
            objp.packets = packets;
            objp.age = age;
            objp.mobile_number = mn;
            strcpy(objp.email, ea);
            strcpy(objp.d_o_BD, dobd);

            objp.store_data();
            flag = A.blood_available(bg_type, packets);
            if (flag == 0)
            {
                
                objp.donor_availability();
            }
            cout << endl;
            break;

        case 4:
            cout << endl;
            for (i = 3; i > 0; i--)
            {
                cout << "Enter password: ";
                cin >> pw;
                flag = objs.enter_donor_pass(pw);
                if (flag == 1)
                {
                    cout << "Records of Donor:" << endl;
                    obj.display_donor();
                    break;
                }
                else
                {
                    cout << "Incorrect Password! Please enter correct password. (" << i - 1 << " chance(s) left.)" << endl
                         << endl;
                }
            }
            break;
        case 5:
            cout << endl;
            for (i = 3; i > 0; i--)
            {
                cout << "Enter password: ";
                cin >> pw;
                flag = objs.enter_patient_pass(pw);
                if (flag == 1)
                {
                    cout << "Records of Patient:" << endl;
                    objp.display_patient();
                    break;
                }
                else
                {
                    cout << "Incorrect Password! Please enter correct password. (" << i - 1 << " chance(s) left.)" << endl
                         << endl;
                }
            }
            break;
        case 0:
            choice = 0;
            A.remove_data();
            A.store_data();
            break;
        default:
            cout << "Invalid choice!" << endl
                 << endl;
        }
    } while (choice);
    return 0;
}
