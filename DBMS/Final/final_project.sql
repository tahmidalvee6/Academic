
-- SMART CITY MANAGEMENT SYSTEM 

--  Create Database
CREATE DATABASE Smart_City_Management_System;
USE Smart_City_Management_System;



--  CENTRAL ADMIN MODULE

CREATE TABLE Central_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(120)
);

INSERT INTO Central_Admin (admin_id, name, email) VALUES
(1, 'Md. Al Amin', 'alamin@smartcity.com'),
(2, 'Tasfia Rahman', 'tasfia@smartcity.com'),
(3, 'Sabbir Hossain', 'sabbir@smartcity.com'),
(4, 'Fatema Akter', 'fatema@smartcity.com'),
(5, 'Raihan Chowdhury', 'raihan@smartcity.com');

SELECT * FROM Central_Admin;


CREATE TABLE Central_Notifications (
    notification_id INT PRIMARY KEY,
    message TEXT,
    date_sent DATE,
    admin_id INT,
    FOREIGN KEY (admin_id) REFERENCES Central_Admin(admin_id)
);

INSERT INTO Central_Notifications (notification_id, message, date_sent, admin_id) VALUES
(1, 'Traffic update: Mirpur Road closed', '2025-11-01', 1),
(2, 'Energy maintenance scheduled', '2025-11-02', 2),
(3, 'Hospital blood donation drive', '2025-11-03', 3),
(4, 'New citizen portal launched', '2025-11-04', 4),
(5, 'City safety alert', '2025-11-05', 5);

SELECT * FROM Central_Notifications;


CREATE TABLE Central_Reports (
    report_id INT PRIMARY KEY,
    module VARCHAR(100),
    report_type VARCHAR(100),
    admin_id INT,
    FOREIGN KEY (admin_id) REFERENCES Central_Admin(admin_id)
);

INSERT INTO Central_Reports (report_id, module, report_type, admin_id) VALUES
(1, 'Traffic', 'Monthly', 1),
(2, 'Energy', 'Weekly', 2),
(3, 'Hospital', 'Quarterly', 3),
(4, 'Citizen', 'Monthly', 4);

SELECT * FROM Central_Reports;







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

INSERT INTO Citizen (citizen_id, name, age, gender, address, contact_no, email) VALUES
(1, 'Md. Rafiq', 30, 'Male', '123 Agrabad, Chittagong', '01710000001', 'rafiq@gmail.com'),
(2, 'Nusrat Jahan', 28, 'Female', '456 Halishahar, Chittagong', '01710000002', 'nusrat@gmail.com'),
(3, 'Shakib Al Hasan', 35, 'Male', '789 Panchlaish, Chittagong', '01710000003', 'shakib@gmail.com'),
(4, 'Tahmina Akter', 32, 'Female', '321 GEC, Chittagong', '01710000004', 'tahmina@gmail.com'),
(5, 'Rasel Hossain', 40, 'Male', '654 Nasirabad, Chittagong', '01710000005', 'rasel@gmail.com');

SELECT * FROM Citizen;



CREATE TABLE Citizen_Complaints (
    complaint_id INT PRIMARY KEY,
    description TEXT,
    status VARCHAR(50),
    citizen_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);

INSERT INTO Citizen_Complaints (complaint_id, description, status, citizen_id) VALUES
(1, 'Street light not working', 'Pending', 1),
(2, 'Garbage collection delay', 'Resolved', 2),
(3, 'Water leakage in pipeline', 'In Progress', 3),
(4, 'Traffic signal malfunction', 'Pending', 4),
(5, 'Noisy construction at night', 'Resolved', 5);


CREATE TABLE Citizen_Feedback (
    feedback_id INT PRIMARY KEY,
    message TEXT,
    citizen_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id)
);


INSERT INTO Citizen_Feedback (feedback_id, message, citizen_id) VALUES
(1, 'Great service at city hospital', 1),
(2, 'Energy bill payment is easy', 2),
(3, 'Traffic fines are reasonable', 3),
(4, 'Portal is user-friendly', 4),
(5, 'Notification system is helpful', 5);



--   TRAFFIC MANAGEMENT MODULE
  
CREATE TABLE Traffic_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

INSERT INTO Traffic_Admin (admin_id, name, central_admin_id) VALUES
(1, 'Rafiul Islam', 1),
(2, 'Shathi Karim', 2),
(3, 'Fahim Ahmed', 3),
(4, 'Rina Sultana', 4),
(5, 'Sabbir Rahman', 5);


CREATE TABLE Traffic_Vehicles (
    vehicle_id INT PRIMARY KEY,
    registration_no VARCHAR(50),
    type VARCHAR(50),
    citizen_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (admin_id) REFERENCES Traffic_Admin(admin_id)
);

INSERT INTO Traffic_Vehicles (vehicle_id, registration_no, type, citizen_id, admin_id) VALUES
(1, 'CTG-1001', 'Car', 1, 1),
(2, 'CTG-1002', 'Motorbike', 2, 2),
(3, 'CTG-1003', 'Car', 3, 3),
(4, 'CTG-1004', 'Truck', 4, 4),
(5, 'CTG-1005', 'Car', 5, 5);


CREATE TABLE Traffic_Violations (
    violation_id INT PRIMARY KEY,
    type VARCHAR(100),
    fine_amount DECIMAL(10,2),
    vehicle_id INT,
    FOREIGN KEY (vehicle_id) REFERENCES Traffic_Vehicles(vehicle_id)
);

INSERT INTO Traffic_Violations (violation_id, type, fine_amount, vehicle_id) VALUES
(1, 'Speeding', 1000, 1),
(2, 'Red Light Jump', 1500, 2),
(3, 'Illegal Parking', 500, 3),
(4, 'No Seatbelt', 300, 4),
(5, 'Wrong Lane', 700, 5);


CREATE TABLE Traffic_Fines (
    fine_id INT PRIMARY KEY,
    amount DECIMAL(10,2),
    payment_status VARCHAR(50),
    violation_id INT,
    FOREIGN KEY (violation_id) REFERENCES Traffic_Violations(violation_id)
);

INSERT INTO Traffic_Fines (fine_id, amount, payment_status, violation_id) VALUES
(1, 1000, 'Paid', 1),
(2, 1500, 'Unpaid', 2),
(3, 500, 'Paid', 3),
(4, 300, 'Pending', 4),
(5, 700, 'Paid', 5);



   -- ENERGY MANAGEMENT MODULE

CREATE TABLE Energy_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

INSERT INTO Energy_Admin (admin_id, name, central_admin_id) VALUES
(1, 'Jahid Hasan', 1),
(2, 'Anika Rahman', 2),
(3, 'Shafiqur Rahman', 3),
(4, 'Nabila Akter', 4),
(5, 'Tushar Karim', 5);



CREATE TABLE Energy_Account (
    account_id INT PRIMARY KEY,
    meter_no VARCHAR(100),
    connection_type VARCHAR(50),
    citizen_id INT,
    admin_id INT,
    FOREIGN KEY (citizen_id) REFERENCES Citizen(citizen_id),
    FOREIGN KEY (admin_id) REFERENCES Energy_Admin(admin_id)
);

INSERT INTO Energy_Account (account_id, meter_no, connection_type, citizen_id, admin_id) VALUES
(1, 'MTR-1001', 'Residential', 1, 1),
(2, 'MTR-1002', 'Commercial', 2, 2),
(3, 'MTR-1003', 'Residential', 3, 3),
(4, 'MTR-1004', 'Commercial', 4, 4),
(5, 'MTR-1005', 'Residential', 5, 5);


CREATE TABLE Energy_Usage (
    usage_id INT PRIMARY KEY,
    units INT,
    month VARCHAR(20),
    account_id INT,
    FOREIGN KEY (account_id) REFERENCES Energy_Account(account_id)
);

INSERT INTO Energy_Usage (usage_id, units, month, account_id) VALUES
(1, 150, 'November', 1),
(2, 200, 'November', 2),
(3, 120, 'November', 3),
(4, 250, 'November', 4),
(5, 180, 'November', 5);


CREATE TABLE Energy_Bill (
    bill_id INT PRIMARY KEY,
    amount DECIMAL(10,2),
    payment_status VARCHAR(50),
    usage_id INT,
    FOREIGN KEY (usage_id) REFERENCES Energy_Usage(usage_id)
);

INSERT INTO Energy_Bill (bill_id, amount, payment_status, usage_id) VALUES
(1, 1800, 'Paid', 1),
(2, 2400, 'Unpaid', 2),
(3, 1440, 'Paid', 3),
(4, 3000, 'Pending', 4),
(5, 2160, 'Paid', 5);


--    HOSPITAL MANAGEMENT MODULE

CREATE TABLE Hospital_Admin (
    admin_id INT PRIMARY KEY,
    name VARCHAR(100),
    central_admin_id INT,
    FOREIGN KEY (central_admin_id) REFERENCES Central_Admin(admin_id)
);

INSERT INTO Hospital_Admin (admin_id, name, central_admin_id) VALUES
(1, 'Dr. Karim', 1),
(2, 'Dr. Jahan', 2),
(3, 'Dr. Rahman', 3),
(4, 'Dr. Akter', 4),
(5, 'Dr. Hossain', 5);


CREATE TABLE Hospitals (
    hospital_id INT PRIMARY KEY,
    name VARCHAR(100),
    location VARCHAR(255),
    capacity INT
);

INSERT INTO Hospitals (hospital_id, name, location, capacity) VALUES
(1, 'Chittagong Medical College', 'Chittagong', 500),
(2, 'Chittagong General Hospital', 'Chittagong', 200),
(3, 'Chittagong Sadar Hospital', 'Chittagong', 300),
(4, 'Chittagong Medical Hospital', 'Chittagong', 150),
(5, 'Chittagong City Hospital', 'Chittagong', 400);



CREATE TABLE Doctors (
    doctor_id INT PRIMARY KEY,
    name VARCHAR(100),
    specialization VARCHAR(100),
    hospital_id INT,
    FOREIGN KEY (hospital_id) REFERENCES Hospitals(hospital_id)
);

INSERT INTO Doctors (doctor_id, name, specialization, hospital_id) VALUES
(1, 'Dr. Rafiq', 'Cardiology', 1),
(2, 'Dr. Nusrat', 'Neurology', 2),
(3, 'Dr. Shakib', 'Orthopedics', 3),
(4, 'Dr. Tahmina', 'Pediatrics', 4),
(5, 'Dr. Rasel', 'General Surgery', 5);


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

INSERT INTO Patients (patient_id, disease, status, citizen_id, doctor_id, admin_id) VALUES
(1, 'Flu', 'Recovering', 1, 1, 1),
(2, 'Migraine', 'Critical', 2, 2, 2),
(3, 'Fracture', 'Stable', 3, 3, 3),
(4, 'Fever', 'Recovering', 4, 4, 4),
(5, 'Allergy', 'Stable', 5, 5, 5);



