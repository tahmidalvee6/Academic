-- SMART CITY MANAGEMENT SYSTEM 


--  Create Database
CREATE DATABASE IF NOT EXISTS Smart_City_Management_System;
USE Smart_City_Management_System;




-- CENTRAL ADMIN MODULE
CREATE TABLE Central_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(120)
);

CREATE TABLE Central_Notifications (
    notification_id INT PRIMARY KEY,
    message TEXT,
    date_sent DATE,
    admin_id INT,
    FOREIGN KEY (admin_id) REFERENCES Central_Admin(admin_id)
);

CREATE TABLE Central_Reports (
    report_id INT PRIMARY KEY,
    module VARCHAR(100),
    report_type VARCHAR(100),
    admin_id INT,
    FOREIGN KEY (admin_id) REFERENCES Central_Admin(admin_id)
);



-- CITIZEN MODULE
CREATE TABLE Citizen (
    citizen_id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    gender VARCHAR(20),
    address VARCHAR(255),
    contact_no VARCHAR(20),
    email VARCHAR(120)
);

CREATE TABLE Citizen_Complaints (
    complaint_id INT PRIMARY KEY,
    description TEXT,
    status VARCHAR(50),
    citizen_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

CREATE TABLE Citizen_Feedback (
    feedback_id INT PRIMARY KEY,
    message TEXT,
    citizen_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);


-- TRAFFIC MANAGEMENT MODULE
CREATE TABLE Traffic_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

CREATE TABLE Traffic_Vehicles (
    vehicle_id INT PRIMARY KEY,
    registration_no VARCHAR(50),
    type VARCHAR(50),
    citizen_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (admin_id) REFERENCES Traffic_Admin(admin_id)
);

CREATE TABLE Traffic_Violations (
    violation_id INT PRIMARY KEY,
    type VARCHAR(100),
    fine_amount DECIMAL(10,2),
    vehicle_id INT,
    FOREIGN KEY (vehicle_id) REFERENCES Traffic_Vehicles(vehicle_id)
);

CREATE TABLE Traffic_Fines (
    fine_id INT PRIMARY KEY,
    amount DECIMAL(10,2),
    payment_status VARCHAR(50),
    violation_id INT,
    FOREIGN KEY (violation_id) REFERENCES Traffic_Violations(violation_id)
);



 -- ENERGY MANAGEMENT MODULE
CREATE TABLE Energy_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

CREATE TABLE Energy_Account (
    account_id INT PRIMARY KEY,
    meter_no VARCHAR(100),
    connection_type VARCHAR(50),
    citizen_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (admin_id) REFERENCES Energy_Admin(admin_id)
);

CREATE TABLE Energy_Usage (
    usage_id INT PRIMARY KEY,
    units INT,
    month VARCHAR(20),
    account_id INT,
    FOREIGN KEY (account_id) REFERENCES Energy_Account(account_id)
);

CREATE TABLE Energy_Bill (
    bill_id INT PRIMARY KEY,
    amount DECIMAL(10,2),
    payment_status VARCHAR(50),
    usage_id INT,
    FOREIGN KEY (usage_id) REFERENCES Energy_Usage(usage_id)
);



 -- HOSPITAL MANAGEMENT MODULE
CREATE TABLE Hospital_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

CREATE TABLE Hospitals (
    hospital_id INT PRIMARY KEY,
    name VARCHAR(100),
    location VARCHAR(255),
    capacity INT
);

CREATE TABLE Doctors (
    doctor_id INT PRIMARY KEY,
    name VARCHAR(100),
    specialization VARCHAR(100),
    hospital_id INT,
    FOREIGN KEY (hospital_id) REFERENCES Hospitals(hospital_id)
);

CREATE TABLE Patients (
    patient_id INT PRIMARY KEY,
    disease VARCHAR(150),
    status VARCHAR(50),
    citizen_id INT,
    doctor_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id),
    FOREIGN KEY (admin_id) REFERENCES Hospital_Admin(admin_id)
);



 -- SMART HOUSING & INFRASTRUCTURE MANAGEMENT
CREATE TABLE Smart_Housing_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

CREATE TABLE Housing_Units (
    unit_id INT PRIMARY KEY,
    address VARCHAR(255),
    unit_type VARCHAR(100),
    size_sqft INT,
    citizen_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (admin_id) REFERENCES Smart_Housing_Admin(admin_id)
);

CREATE TABLE Maintenance_Requests (
    request_id INT PRIMARY KEY,
    issue_description TEXT,
    request_date DATE,
    status VARCHAR(50),
    unit_id INT,
    FOREIGN KEY (unit_id) REFERENCES Housing_Units(unit_id)
);

CREATE TABLE Infrastructure_Projects (
    project_id INT PRIMARY KEY,
    project_name VARCHAR(150),
    project_type VARCHAR(100),
    start_date DATE,
    end_date DATE,
    admin_id INT,
    FOREIGN KEY (admin_id) REFERENCES Smart_Housing_Admin(admin_id)
);

