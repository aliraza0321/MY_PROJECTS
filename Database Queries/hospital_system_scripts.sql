--Tables creation
CREATE TABLE Users (
    user_id INT not null,
    name VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(100),
    role VARCHAR(50),
    phone VARCHAR(15)
);

CREATE TABLE Patients (
    patient_id INT not null ,
    age INT,
    gender VARCHAR(10),
    blood_group VARCHAR(5)
);

CREATE TABLE Doctors (
    doctor_id INT not null,
    specialization VARCHAR(100),
    experience INT
);

CREATE TABLE Appointments (
    appointment_id INT not null,
    patient_id INT not null,
    doctor_id INT not null ,
    appointment_date DATE,
    status VARCHAR(50)
);

CREATE TABLE Medicines (
    medicine_id INT not null ,
    name VARCHAR(100),
    price DECIMAL(10,2),
    stock INT
);

CREATE TABLE Prescriptions (
    prescription_id INT not null ,
    patient_id INT not null,
    doctor_id INT not null,
    date DATE
);

CREATE TABLE Prescription_Details (
    id INT not null,
    prescription_id INT not null,
    medicine_id INT not null,
    dosage VARCHAR(100)
);

CREATE TABLE Billing (
    bill_id INT not null,
    patient_id INT not null,
    total_amount DECIMAL(10,2),
    status VARCHAR(50)
);

--add primary key constraints
ALTER TABLE Users add constraint p1  PRIMARY KEY (user_id);

ALTER TABLE Patients add constraint p2 PRIMARY KEY (patient_id);

ALTER TABLE Doctors add constraint p3  PRIMARY KEY (doctor_id);

ALTER TABLE Appointments add constraint p4  PRIMARY KEY (appointment_id);

ALTER TABLE Medicines add constraint p5  PRIMARY KEY (medicine_id);

ALTER TABLE Prescriptions add constraint p6  PRIMARY KEY (prescription_id);

ALTER TABLE Prescription_Details add constraint p7  PRIMARY KEY (id);

ALTER TABLE Billing add constraint p8 PRIMARY KEY (bill_id);

--add foreign key constraints
ALTER TABLE Patients add constraint f_k FOREIGN KEY (patient_id) REFERENCES Users(user_id)
on delete cascade on update cascade;

ALTER TABLE Doctors add constraint f_k1
 FOREIGN KEY (doctor_id) REFERENCES Users(user_id)
on delete cascade on update cascade ;

ALTER TABLE Appointments add constraint f2
 FOREIGN KEY (patient_id) REFERENCES Patients(patient_id)
on delete cascade on update cascade;

ALTER TABLE Appointments add constraint f3
 FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
on delete cascade on update cascade;

ALTER TABLE Prescriptions add constraint f4
 FOREIGN KEY (patient_id) REFERENCES Patients(patient_id)
on delete cascade on update cascade;

ALTER TABLE Prescriptions add constraint f5
FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
on delete cascade on update cascade;

ALTER TABLE Prescription_Details add constraint f6
 FOREIGN KEY (prescription_id) REFERENCES Prescriptions(prescription_id)
on delete cascade on update cascade;

ALTER TABLE Prescription_Details add constraint f7
FOREIGN KEY (medicine_id) REFERENCES Medicines(medicine_id)
on delete cascade on update cascade;

ALTER TABLE Billing add constraint f8
FOREIGN KEY (patient_id) REFERENCES Patients(patient_id)
on delete cascade on update cascade;

--insertion data
INSERT INTO Users VALUES
(1, 'Ali', 'ali@gmail.com', '123', 'patient', '0300'),
(2, 'Dr Ahmed', 'ahmed@gmail.com', '123', 'doctor', '0311');

INSERT INTO Patients VALUES
(1, 22, 'Male', 'B+');

INSERT INTO Doctors VALUES
(2, 'Cardiology', 5);

INSERT INTO Appointments VALUES
(1, 1, 2, '2026-04-15', 'Scheduled');

INSERT INTO Medicines VALUES
(1, 'Panadol', 50, 100);

INSERT INTO Prescriptions VALUES
(1, 1, 2, '2026-04-11');

INSERT INTO Prescription_Details VALUES
(1, 1, 1, '2 times daily');

INSERT INTO Billing VALUES
(1, 1, 500, 'Paid');