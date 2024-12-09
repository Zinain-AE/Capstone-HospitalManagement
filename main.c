#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int age;
    char gender[10];
    char illness[100];
    char doctorAssigned[100];
    char appointmentTime[20];
};

struct Doctor {
    int id;
    char name[100];
    char specialty[100];
    char contactInfo[100];
};

struct Appointment {
    int id;
    int patientId;
    int doctorId;
    char date[20];
    char time[10];
};

struct Bill {
    int id;
    int patientId;
    float totalAmount;
    float paidAmount;
    float balanceAmount;
};


void login();
void patientLogin();
void loadPatients();
void savePatients();
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void doctorLogin();
void loadDoctors();
void saveDoctors();
void addDoctor();
void viewDoctors();
void searchDoctor();
void updateDoctor();
void deleteDoctor();
void loadAppointments();
void saveAppointments();
void addAppointment();
void viewAppointments();
void searchAppointment();
void updateAppointment();
void deleteAppointment();
void loadBills();
void saveBills();
void addBill();
void viewBills();
void searchBill();
void updateBill();
void deleteBill();

struct Patient patients[1000];
struct Doctor doctors[500];
struct Appointment appointments[2000];
struct Bill bills[2000];
int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int billCount = 0;

int main() {
    login();
    int choice;

   while (1) {
    printf("\n************************************************************\n");
    printf("*                                                          *\n");
    printf("*             *** HOSPITAL MANAGEMENT SYSTEM ***           *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*               Your Health, Our Priority                 *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("*                        MAIN MENU                         *\n");
    printf("************************************************************\n");
    printf("*   [1] Patient Management                                 *\n");
    printf("*   [2] Doctor Management                                  *\n");
    printf("*   [3] Appointment Management                             *\n");
    printf("*   [4] Billing Management                                 *\n");
    printf("*   [5] Patient Login                                      *\n");
    printf("*   [6] Doctor Login                                       *\n");
    printf("*   [0] Exit                                               *\n");
    printf("************************************************************\n");
    printf("*   Enter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int subChoice;
                 loadPatients();
                while (1) {
                    printf("\n1. Add Patient\n2. View Patients\n3. Search Patient\n4. Update Patient\n5. Delete Patient\n0. Back to Main Menu\n");
                    printf("Select an option: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1: addPatient(); break;
                        case 2: viewPatients(); break;
                        case 3: searchPatient(); break;
                        case 4: updatePatient(); break;
                        case 5: deletePatient(); break;
                        case 6: savePatients(); break;
                        case 0: goto mainMenu;
                        default: printf("Invalid input. Please try again.\n");
                    }
                }
                mainMenu:
                break;
            }

            case 2: {
                int subChoice;
                loadDoctors();
                while (1) {
                    printf("\n1. Add Doctor\n2. View Doctors\n3. Search Doctor\n4. Update Doctor\n5. Delete Doctor\n0. Back to Main Menu\n");
                    printf("Select an option: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1: addDoctor(); break;
                        case 2: viewDoctors(); break;
                        case 3: searchDoctor(); break;
                        case 4: updateDoctor(); break;
                        case 5: deleteDoctor(); break;
                         case 6: saveDoctors(); break;
                        case 0: goto mainMenu2;
                        default: printf("Invalid input. Please try again.\n");
                    }
                }
                mainMenu2:
                break;
            }

            case 3: {
                int subChoice;
                loadAppointments();
                while (1) {
                    printf("\n1. Add Appointment\n2. View Appointments\n3. Search Appointment\n4. Update Appointment\n5. Delete Appointment\n0. Back to Main Menu\n");
                    printf("Select an option: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1: addAppointment(); break;
                        case 2: viewAppointments(); break;
                        case 3: searchAppointment(); break;
                        case 4: updateAppointment(); break;
                        case 5: deleteAppointment(); break;
                         case 6: saveAppointments(); break;
                        case 0: goto mainMenu3;
                        default: printf("Invalid input. Please try again.\n");
                    }
                }
                mainMenu3:
                break;
            }

            case 4: {
                int subChoice;
                void loadBills();
                while (1) {
                    printf("\n1. Add Bill\n2. View Bills\n3. Search Bill\n4. Update Bill\n5. Delete Bill\n0. Back to Main Menu\n");
                    printf("Select an option: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1: addBill(); break;
                        case 2: viewBills(); break;
                        case 3: searchBill(); break;
                        case 4: updateBill(); break;
                        case 5: deleteBill(); break;
                         case 6: saveBills(); break;
                        case 0: goto mainMenu4;
                        default: printf("Invalid input. Please try again.\n");
                    }
                }
                mainMenu4:
                break;
            }
            case 5:
                loadPatients();
                patientLogin();
                break;
            case 6:
                loadDoctors();
                doctorLogin();
                break;

            case 0:
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
}

void login() {
    char username[50];
    char password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter Password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
            printf("Login successful!\n");
            return;
        } else {
            printf("Incorrect username or password. Attempts remaining: %d\n", --attempts);
        }
    }
    printf("Too many failed attempts. Exiting program.\n");
    exit(1);
}


void loadPatients() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\patients.dat", "rb");
    if (file != NULL) {
        fread(&patientCount, sizeof(int), 1, file);
        fread(patients, sizeof(struct Patient), patientCount, file);
        fclose(file);
    } else {
        printf("No existing patient data found. Starting fresh.\n");
    }
}

void savePatients() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\patients.dat", "wb");
    if (file != NULL) {
        fwrite(&patientCount, sizeof(int), 1, file);
        fwrite(patients, sizeof(struct Patient), patientCount, file);
        fclose(file);
    } else {
        printf("Error: Unable to save patient data.\n");
    }
}

void addPatient() {
    struct Patient newPatient;
    newPatient.id = patientCount + 1;

    printf("Enter Patient Name: ");
    scanf("%s",&newPatient.name );
    printf("Enter Patient Age: ");
    scanf("%d", &newPatient.age);

    while (1) {
        printf("Enter Patient Gender (male/female): ");
        scanf("%s", newPatient.gender);
        if (strcmp(newPatient.gender, "male") == 0 || strcmp(newPatient.gender, "female") == 0) {
            break;
        } else {
            printf("Invalid input. Please enter 'male' or 'female'.\n");
        }
    }

    printf("Enter Illness: ");
    scanf("%s", newPatient.illness);
    printf("Assign Doctor: ");
    scanf("%s", newPatient.doctorAssigned);

    patients[patientCount++] = newPatient;
    savePatients();
    printf("Patient added successfully!\n");
}

void viewPatients() {
    printf("\n---- Patient List ----\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Illness: %s | Doctor Assigned: %s\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].illness, patients[i].doctorAssigned);
    }
}

void searchPatient() {
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("ID: %d | Name: %s | Age: %d | Gender: %s | Illness: %s | Doctor Assigned: %s\n",
                   patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].illness, patients[i].doctorAssigned);
            return;
        }
    }
    printf("Patient not found.\n");
}

void updatePatient() {
    int id;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", patients[i].name);
            printf("Age: ");
            scanf("%d", &patients[i].age);

            while (1) {
                printf("Gender (male/female): ");
                scanf("%s", patients[i].gender);
                if (strcmp(patients[i].gender, "male") == 0 || strcmp(patients[i].gender, "female") == 0) {
                    break;
                } else {
                    printf("Invalid input. Please enter 'male' or 'female'.\n");
                }
            }

            printf("Illness: ");
            scanf("%s", patients[i].illness);
            printf("Doctor Assigned: ");
            scanf("%s", patients[i].doctorAssigned);

            savePatients();
            printf("Patient updated successfully!\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

void deletePatient() {
    int id;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            savePatients();
            printf("Patient deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found.\n");
}
void patientLogin() {
    char name[100];
    int id;
    printf("Enter your Patient ID: ");
    scanf("%d", &id);
    printf("Enter your Name: ");
    scanf("%s", name);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id && strcmp(patients[i].name, name) == 0) {
            printf("\n---- Your Information ----\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Illness: %s\n", patients[i].illness);
            printf("Doctor Assigned: %s\n", patients[i].doctorAssigned);
            printf("Appointment Time: %s\n", patients[i].appointmentTime);
            return;
        }
    }
    printf("Invalid ID or Name. Access denied.\n");
}

void loadDoctors() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\doctors.dat", "rb");
    if (file != NULL) {
        fread(&doctorCount, sizeof(int), 1, file);
        fread(doctors, sizeof(struct Doctor), doctorCount, file);
        fclose(file);
    } else {
        printf("No existing doctor data found. Starting fresh.\n");
    }
}

void saveDoctors() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\doctors.dat", "wb");
    if (file != NULL) {
        fwrite(&doctorCount, sizeof(int), 1, file);
        fwrite(doctors, sizeof(struct Doctor), doctorCount, file);
        fclose(file);
    } else {
        printf("Error: Unable to save doctor data.\n");
    }
}

void addDoctor() {
    struct Doctor newDoctor;
    newDoctor.id = doctorCount + 1;

    printf("Enter Doctor Name: ");
    scanf("%s", newDoctor.name);
    printf("Enter Specialty: ");
    scanf("%s", newDoctor.specialty);
    printf("Enter Contact Info: ");
    scanf("%s", newDoctor.contactInfo);

    doctors[doctorCount++] = newDoctor;
    saveDoctors(); // Save to file after adding
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    printf("\n---- Doctor List ----\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %d | Name: %s | Specialty: %s | Contact Info: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialty, doctors[i].contactInfo);
    }
}

void searchDoctor() {
    int id;
    printf("Enter Doctor ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            printf("ID: %d | Name: %s | Specialty: %s | Contact Info: %s\n",
                   doctors[i].id, doctors[i].name, doctors[i].specialty, doctors[i].contactInfo);
            return;
        }
    }
    printf("Doctor not found.\n");
}

void updateDoctor() {
    int id;
    printf("Enter Doctor ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", doctors[i].name);
            printf("Specialty: ");
            scanf("%s", doctors[i].specialty);
            printf("Contact Info: ");
            scanf("%s", doctors[i].contactInfo);

            saveDoctors(); // Save to file after updating
            printf("Doctor updated successfully!\n");
            return;
        }
    }
    printf("Doctor not found.\n");
}

void deleteDoctor() {
    int id;
    printf("Enter Doctor ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            for (int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            saveDoctors(); // Save to file after deleting
            printf("Doctor deleted successfully!\n");
            return;
        }
    }
    printf("Doctor not found.\n");
}
void doctorLogin() {
    char doctorName[100];
    int doctorId;

    printf("\n--- Doctor Login ---\n");
    printf("Enter Doctor Name: ");
    scanf("%s", doctorName);
    printf("Enter Doctor ID: ");
    scanf("%d", &doctorId);

    // Verify doctor credentials
    int found = 0;
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].name, doctorName) == 0 && doctors[i].id == doctorId) {
            found = 1;
            printf("\nLogin successful! Welcome, Dr. %s\n", doctors[i].name);
            printf("\n--- Patients Assigned to You ---\n");

            int patientFound = 0;
            for (int j = 0; j < patientCount; j++) {
                // Match doctorAssigned with the logged-in doctor's name
                if (strcmp(patients[j].doctorAssigned, doctors[i].name) == 0) {
                    patientFound = 1;
                    printf("ID: %d | Name: %s | Age: %d | Gender: %s | Illness: %s\n",
                           patients[j].id, patients[j].name, patients[j].age,
                           patients[j].gender, patients[j].illness);
                }
            }

            if (!patientFound) {
                printf("No patients assigned to you yet.\n");
            }
            return;
        }
    }

    if (!found) {
        printf("Invalid credentials. Please try again.\n");
    }
}

void loadAppointments() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\appointments.dat", "rb");
    if (file != NULL) {
        fread(&appointmentCount, sizeof(int), 1, file);
        fread(appointments, sizeof(struct Appointment), appointmentCount, file);
        fclose(file);
    } else {
        printf("No existing appointment records found. Starting fresh.\n");
    }
}

// Function to save appointments to file
void saveAppointments() {
    FILE *file = fopen("appointments.dat", "wb");
    if (file != NULL) {
        fwrite(&appointmentCount, sizeof(int), 1, file);
        fwrite(appointments, sizeof(struct Appointment), appointmentCount, file);
        fclose(file);
    } else {
        printf("Error: Unable to save appointment data.\n");
    }
}

// Function to add an appointment
void addAppointment() {
    struct Appointment newAppointment;
    newAppointment.id = appointmentCount + 1;

  printf("Enter Patient ID: ");
    scanf("%d", &newAppointment.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &newAppointment.doctorId);
    printf("Enter Appointment Date (dd/mm/yyyy): ");
    scanf("%s", newAppointment.date);
    printf("Enter Appointment Time (hh:mm): ");
    scanf("%s", newAppointment.time);

    appointments[appointmentCount++] = newAppointment;
    saveAppointments();

    printf("Appointment added successfully!\n");
}
void viewAppointments() {
    printf("\n---- Appointment List ----\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("ID: %d | Patient ID: %d | Doctor ID: %d | Date: %s | Time: %s\n",
               appointments[i].id, appointments[i].patientId, appointments[i].doctorId, appointments[i].date, appointments[i].time);
    }
}

void searchAppointment() {
    int id;
    printf("Enter Appointment ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id) {
            printf("ID: %d | Patient ID: %d | Doctor ID: %d | Date: %s | Time: %s\n",
                   appointments[i].id, appointments[i].patientId, appointments[i].doctorId, appointments[i].date, appointments[i].time);
            return;
        }
    }
    printf("Appointment not found.\n");
}

void updateAppointment() {
    int id;
    printf("Enter Appointment ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id) {
            printf("Enter new details:\n");
            printf("Patient ID: ");
            scanf("%d", &appointments[i].patientId);
            printf("Doctor ID: ");
            scanf("%d", &appointments[i].doctorId);
            printf("Date (dd/mm/yyyy): ");
            scanf("%s", appointments[i].date);
            printf("Time (hh:mm): ");
            scanf("%s", appointments[i].time);

            printf("Appointment updated successfully!\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}

void deleteAppointment() {
    int id;
    printf("Enter Appointment ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id) {
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
               saveAppointments();
            printf("Appointment deleted successfully!\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}

void loadBills() {
    FILE *file = fopen("C:\\Users\\IT BD\\Documents\\AA Capston Project\\bills.dat", "rb");
    if (file != NULL) {
        fread(&billCount, sizeof(int), 1, file);
        fread(bills, sizeof(struct Bill), billCount, file);
        fclose(file);
    } else {
        printf("No existing bill data found. Starting fresh.\n");
    }
}

void saveBills() {
    FILE *file = fopen("bills.dat", "wb");
    if (file != NULL) {
        fwrite(&billCount, sizeof(int), 1, file);
        fwrite(bills, sizeof(struct Bill), billCount, file);
        fclose(file);
    } else {
        printf("Error: Unable to save bill data.\n");
    }
}


void addBill() {
    struct Bill newBill;
    newBill.id = billCount + 1;

    printf("Enter Patient ID: ");
    scanf("%d", &newBill.patientId);
    printf("Enter Total Amount: ");
    scanf("%f", &newBill.totalAmount);
    printf("Enter Paid Amount: ");
    scanf("%f", &newBill.paidAmount);


    newBill.balanceAmount = newBill.totalAmount - newBill.paidAmount;

    bills[billCount++] = newBill;
    saveBills();
    printf("Bill added successfully!\n");
}

void viewBills() {
    printf("\n---- Bill List ----\n");
    for (int i = 0; i < billCount; i++) {
        printf("ID: %d | Patient ID: %d | Total Amount: %.2f | Paid Amount: %.2f | Balance Amount: %.2f\n",
               bills[i].id, bills[i].patientId, bills[i].totalAmount, bills[i].paidAmount, bills[i].balanceAmount);
    }
}

void searchBill() {
    int id;
    printf("Enter Bill ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < billCount; i++) {
        if (bills[i].id == id) {
            printf("ID: %d | Patient ID: %d | Total Amount: %.2f | Paid Amount: %.2f | Balance Amount: %.2f\n",
                   bills[i].id, bills[i].patientId, bills[i].totalAmount, bills[i].paidAmount, bills[i].balanceAmount);
            return;
        }
    }
    printf("Bill not found.\n");
}

void updateBill() {
    int id;
    printf("Enter Bill ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < billCount; i++) {
        if (bills[i].id == id) {
            printf("Enter new details:\n");
            printf("Patient ID: ");
            scanf("%d", &bills[i].patientId);
            printf("Total Amount: ");
            scanf("%f", &bills[i].totalAmount);
            printf("Paid Amount: ");
            scanf("%f", &bills[i].paidAmount);


            bills[i].balanceAmount = bills[i].totalAmount - bills[i].paidAmount;
            saveBills();

            printf("Bill updated successfully!\n");
            return;
        }
    }
    printf("Bill not found.\n");
}

void deleteBill() {
    int id;
    printf("Enter Bill ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < billCount; i++) {
        if (bills[i].id == id) {
            for (int j = i; j < billCount - 1; j++) {
                bills[j] = bills[j + 1];
            }
            billCount--;
            saveBills();
            printf("Bill deleted successfully!\n");
            return;
        }
    }
    printf("Bill not found.\n");
}
