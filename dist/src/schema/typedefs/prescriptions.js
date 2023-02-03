"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.PrescriptionListType = exports.PrescriptionType = void 0;
const graphql_1 = require("graphql");
const prescriptions_1 = require("../../models/prescriptions");
exports.PrescriptionType = new graphql_1.GraphQLObjectType({
    name: "All_Prescriptions_Available",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        drug: { type: graphql_1.GraphQLString },
        dosage: { type: graphql_1.GraphQLString },
        interval: { type: graphql_1.GraphQLString },
    }),
});
exports.PrescriptionListType = new graphql_1.GraphQLObjectType({
    name: "Patient_Prescription",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        visit_id: { type: graphql_1.GraphQLInt },
        prescription: {
            type: exports.PrescriptionType,
            resolve: (parent) => {
                return prescriptions_1.Prescription.findOne({
                    where: {
                        id: parent.prescription
                    }
                });
            }
        },
    }),
});
