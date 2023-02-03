"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.AllVisitsByDoctor = exports.DoctorsQuery = exports.PatientsQuery = exports.VisitsQuery = exports.PrescriptionsQuery = exports.TestsQuery = exports.AllergiesQuery = exports.BloodGroupsQuery = void 0;
const graphql_1 = require("graphql");
const allergies_1 = require("../../models/allergies");
const blood_group_1 = require("../../models/blood_group");
const doctor_1 = require("../../models/doctor");
const patient_1 = require("../../models/patient");
const prescriptions_1 = require("../../models/prescriptions");
const tests_1 = require("../../models/tests");
const visits_1 = require("../../models/visits");
const allergies_2 = require("../typedefs/allergies");
const blood_group_2 = require("../typedefs/blood_group");
const doctor_2 = require("../typedefs/doctor");
const patient_2 = require("../typedefs/patient");
const prescriptions_2 = require("../typedefs/prescriptions");
const tests_2 = require("../typedefs/tests");
const visits_2 = require("../typedefs/visits");
exports.BloodGroupsQuery = {
    type: new graphql_1.GraphQLList(blood_group_2.BloodGroupType),
    resolve() {
        return blood_group_1.BloodGroup.findAll();
    },
};
exports.AllergiesQuery = {
    type: new graphql_1.GraphQLList(allergies_2.AllergyType),
    resolve() {
        return allergies_1.Allergies.findAll();
    },
};
exports.TestsQuery = {
    type: new graphql_1.GraphQLList(tests_2.TestType),
    resolve() {
        return tests_1.Tests.findAll();
    },
};
exports.PrescriptionsQuery = {
    type: new graphql_1.GraphQLList(prescriptions_2.PrescriptionType),
    resolve() {
        return prescriptions_1.Prescription.findAll();
    },
};
exports.VisitsQuery = {
    type: new graphql_1.GraphQLList(visits_2.VisitsType),
    resolve() {
        return visits_1.Visits.findAll();
    }
};
exports.PatientsQuery = {
    type: new graphql_1.GraphQLList(patient_2.PatientType),
    resolve() {
        return patient_1.Patient.findAll();
    }
};
exports.DoctorsQuery = {
    type: new graphql_1.GraphQLList(doctor_2.DoctorsType),
    resolve() {
        return doctor_1.Doctors.findAll();
    }
};
exports.AllVisitsByDoctor = {
    type: new graphql_1.GraphQLList(visits_2.VisitsType),
    args: {
        id: { type: graphql_1.GraphQLID }
    },
    resolve: (parent, args) => {
        return visits_1.Visits.findAll({
            where: {
                doctor_visited: args.id
            }
        });
    }
};
