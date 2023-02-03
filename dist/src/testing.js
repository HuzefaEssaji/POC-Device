"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const bloodgroups_json_1 = __importDefault(require("./sample/bloodgroups.json"));
const tests_json_1 = __importDefault(require("./sample/tests.json"));
const allergies_json_1 = __importDefault(require("./sample/allergies.json"));
const prescription_json_1 = __importDefault(require("./sample/prescription.json"));
const patients_json_1 = __importDefault(require("./sample/patients.json"));
const visits_json_1 = __importDefault(require("./sample/visits.json"));
const doctors_json_1 = __importDefault(require("./sample/doctors.json"));
const prescription_list_json_1 = __importDefault(require("./sample/prescription_list.json"));
const allergies_list_json_1 = __importDefault(require("./sample/allergies_list.json"));
const tests_list_json_1 = __importDefault(require("./sample/tests_list.json"));
const blood_group_1 = require("./models/blood_group");
const tests_1 = require("./models/tests");
const allergies_1 = require("./models/allergies");
const prescriptions_1 = require("./models/prescriptions");
const patient_1 = require("./models/patient");
const visits_1 = require("./models/visits");
const doctor_1 = require("./models/doctor");
function TestingData() {
    blood_group_1.BloodGroup.bulkCreate(bloodgroups_json_1.default);
    tests_1.Tests.bulkCreate(tests_json_1.default);
    allergies_1.Allergies.bulkCreate(allergies_json_1.default);
    prescriptions_1.Prescription.bulkCreate(prescription_json_1.default);
    patient_1.Patient.bulkCreate(patients_json_1.default);
    doctor_1.Doctors.bulkCreate(doctors_json_1.default);
    visits_1.Visits.bulkCreate(visits_json_1.default);
    prescriptions_1.PrescriptionList.bulkCreate(prescription_list_json_1.default);
    allergies_1.AllergiesList.bulkCreate(allergies_list_json_1.default);
    tests_1.TestsList.bulkCreate(tests_list_json_1.default);
}
exports.default = TestingData;
