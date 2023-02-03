"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.VisitsType = void 0;
const graphql_1 = require("graphql");
const doctor_1 = require("../../models/doctor");
const prescriptions_1 = require("../../models/prescriptions");
const tests_1 = require("../../models/tests");
const doctor_2 = require("./doctor");
const prescriptions_2 = require("./prescriptions");
const tests_2 = require("./tests");
exports.VisitsType = new graphql_1.GraphQLObjectType({
    name: "All_of_the_Visits",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        patient: { type: graphql_1.GraphQLInt },
        date: { type: graphql_1.GraphQLString },
        weight: { type: graphql_1.GraphQLString },
        height: { type: graphql_1.GraphQLString },
        temperature: { type: graphql_1.GraphQLString },
        bp: { type: graphql_1.GraphQLString },
        ecg: { type: graphql_1.GraphQLString },
        prescriptions: {
            type: new graphql_1.GraphQLList(prescriptions_2.PrescriptionListType),
            resolve: (visit) => {
                return prescriptions_1.PrescriptionList.findAll({
                    where: {
                        visit_id: visit.id
                    }
                });
            }
        },
        tests: {
            type: new graphql_1.GraphQLList(tests_2.TestListType),
            resolve: (visit) => {
                return tests_1.TestsList.findAll({
                    where: {
                        visit_id: visit.id
                    }
                });
            }
        },
        doctor_visited: {
            type: doctor_2.DoctorsType,
            resolve: (parent) => {
                return doctor_1.Doctors.findOne({
                    where: {
                        id: parent.doctor_visited
                    }
                });
            }
        }
    }),
});
