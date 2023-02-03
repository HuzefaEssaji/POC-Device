"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.PatientType = void 0;
const graphql_1 = require("graphql");
const allergies_1 = require("../../models/allergies");
const visits_1 = require("../../models/visits");
const allergies_2 = require("./allergies");
const blood_group_1 = require("./blood_group");
const visits_2 = require("./visits");
exports.PatientType = new graphql_1.GraphQLObjectType({
    name: "All_of_the_Patients",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        uid: { type: graphql_1.GraphQLInt },
        name: { type: graphql_1.GraphQLString },
        aadhar: { type: graphql_1.GraphQLString },
        email: { type: graphql_1.GraphQLString },
        father_name: { type: graphql_1.GraphQLString },
        mother_name: { type: graphql_1.GraphQLString },
        address: { type: graphql_1.GraphQLString },
        date_of_birth: { type: graphql_1.GraphQLString },
        blood_group: { type: blood_group_1.BloodGroupType },
        allergies: {
            type: new graphql_1.GraphQLList(allergies_2.AllergyListType),
            resolve: (patient) => {
                return allergies_1.AllergiesList.findAll({
                    where: {
                        patient_id: patient.id
                    }
                });
            }
        },
        current_weight: { type: graphql_1.GraphQLString },
        current_height: { type: graphql_1.GraphQLString },
        gender: { type: graphql_1.GraphQLString },
        city: { type: graphql_1.GraphQLString },
        pin: { type: graphql_1.GraphQLString },
        state: { type: graphql_1.GraphQLString },
        visits: {
            type: new graphql_1.GraphQLList(visits_2.VisitsType),
            resolve: (patient) => {
                return visits_1.Visits.findAll({
                    where: {
                        patient: patient.id
                    }
                });
            }
        }
    }),
});
