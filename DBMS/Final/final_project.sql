-- SMART CITY MANAGEMENT SYSTEM 

CREATE DATABASE Smart_City_Management_System;

USE Smart_City_Management_System;


-- 1️. CENTRAL ADMIN PANEL
CREATE TABLE Admin_Main (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE,
    password VARCHAR(255),
    role ENUM('SuperAdmin','CityManager') DEFAULT 'SuperAdmin',
    contact_no VARCHAR(20)
);

CREATE TABLE ServiceLogs (
    log_id INT PRIMARY KEY AUTO_INCREMENT,
    admin_id INT,
    module VARCHAR(50),
    action VARCHAR(100),
    description TEXT,
    log_time DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (admin_id) REFERENCES Admin_Main(admin_id)
);

CREATE TABLE Notifications (
    notification_id INT PRIMARY KEY AUTO_INCREMENT,
    admin_id INT,
    citizen_id INT,
    message TEXT,
    date_sent DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Reports (
    report_id INT PRIMARY KEY AUTO_INCREMENT,
    admin_id INT,
    module VARCHAR(50),
    report_type VARCHAR(100),
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (admin_id) REFERENCES Admin_Main(admin_id)
);


-- 2️. CITIZEN MODULE
CREATE TABLE Citizen (
    citizen_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    age INT,
    gender VARCHAR(10),
    address VARCHAR(255),
    contact_no VARCHAR(20),
    email VARCHAR(100) UNIQUE,
    password VARCHAR(255)
);

CREATE TABLE Complaints (
    complaint_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    service_type VARCHAR(50),
    description TEXT,
    status VARCHAR(20),
    date_created DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

CREATE TABLE Feedback (
    feedback_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    service_type VARCHAR(50),
    message TEXT,
    date DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

CREATE TABLE Payments (
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    service_type VARCHAR(50),
    amount DECIMAL(10,2),
    payment_date DATETIME DEFAULT CURRENT_TIMESTAMP,
    payment_status VARCHAR(20),
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);


-- 3️. TRAFFIC MANAGEMENT
CREATE TABLE Admin_Traffic (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    access_level VARCHAR(50)
);

CREATE TABLE Vehicles (
    vehicle_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    registration_no VARCHAR(50),
    type VARCHAR(50),
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

CREATE TABLE Violations (
    violation_id INT PRIMARY KEY AUTO_INCREMENT,
    vehicle_id INT,
    type VARCHAR(100),
    fine_amount DECIMAL(10,2),
    status VARCHAR(20),
    FOREIGN KEY (vehicle_id) REFERENCES Vehicles(vehicle_id)
);

CREATE TABLE Traffic_Fines (
    fine_id INT PRIMARY KEY AUTO_INCREMENT,
    violation_id INT,
    amount DECIMAL(10,2),
    payment_status VARCHAR(20),
    payment_date DATETIME,
    FOREIGN KEY (violation_id) REFERENCES Violations(violation_id)
);


-- 4️. WASTE MANAGEMENT
CREATE TABLE Admin_Waste (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    access_level VARCHAR(50)
);

CREATE TABLE Zones (
    zone_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    population INT,
    cleanliness_level VARCHAR(20)
);

CREATE TABLE CollectionVehicles (
    vehicle_id INT PRIMARY KEY AUTO_INCREMENT,
    driver_name VARCHAR(100),
    vehicle_no VARCHAR(20),
    zone_id INT,
    FOREIGN KEY (zone_id) REFERENCES Zones(zone_id)
);

CREATE TABLE CollectionSchedule (
    schedule_id INT PRIMARY KEY AUTO_INCREMENT,
    zone_id INT,
    collection_day VARCHAR(20),
    time TIME,
    FOREIGN KEY (zone_id) REFERENCES Zones(zone_id)
);


-- 5️. HEALTH MANAGEMENT
CREATE TABLE Admin_Health (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    access_level VARCHAR(50)
);

CREATE TABLE Hospitals (
    hospital_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    location VARCHAR(100),
    capacity INT,
    contact_no VARCHAR(20)
);

CREATE TABLE Doctors (
    doctor_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    specialization VARCHAR(100),
    hospital_id INT,
    FOREIGN KEY (hospital_id) REFERENCES Hospitals(hospital_id)
);

CREATE TABLE Patients (
    patient_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    doctor_id INT,
    disease VARCHAR(100),
    admission_date DATE,
    status VARCHAR(20),
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
);


-- 6️. ENERGY MANAGEMENT
CREATE TABLE Admin_Energy (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    access_level VARCHAR(50)
);

CREATE TABLE EnergyAccount (
    account_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    meter_no VARCHAR(50),
    connection_type VARCHAR(50),
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

CREATE TABLE EnergyUsage (
    usage_id INT PRIMARY KEY AUTO_INCREMENT,
    account_id INT,
    month VARCHAR(20),
    units_consumed DECIMAL(10,2),
    FOREIGN KEY (account_id) REFERENCES EnergyAccount(account_id)
);

CREATE TABLE EnergyBill (
    bill_id INT PRIMARY KEY AUTO_INCREMENT,
    usage_id INT,
    amount DECIMAL(10,2),
    due_date DATE,
    payment_status VARCHAR(20),
    FOREIGN KEY (usage_id) REFERENCES EnergyUsage(usage_id)
);


-- 7️. SMART HOUSING & INFRASTRUCTURE
CREATE TABLE Admin_Housing (
    admin_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    access_level VARCHAR(50)
);

CREATE TABLE Buildings (
    building_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100),
    location VARCHAR(100),
    type VARCHAR(50),
    total_floors INT
);

CREATE TABLE Apartments (
    apartment_id INT PRIMARY KEY AUTO_INCREMENT,
    building_id INT,
    apartment_no VARCHAR(20),
    size_sqft DECIMAL(10,2),
    rent DECIMAL(10,2),
    FOREIGN KEY (building_id) REFERENCES Buildings(building_id)
);

CREATE TABLE Residents (
    resident_id INT PRIMARY KEY AUTO_INCREMENT,
    citizen_id INT,
    apartment_id INT,
    move_in_date DATE,
    status VARCHAR(20),
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (apartment_id) REFERENCES Apartments(apartment_id)
);
