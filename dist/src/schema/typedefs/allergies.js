"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.AllergyListType = exports.AllergyType = void 0;
const graphql_1 = require("graphql");
const allergies_1 = require("../../models/allergies");
exports.AllergyType = new graphql_1.GraphQLObjectType({
    name: "Allergies",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        name: { type: graphql_1.GraphQLString },
    }),
});
exports.AllergyListType = new graphql_1.GraphQLObjectType({
    name: "Allergy_of_Patients",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        patient_id: { type: graphql_1.GraphQLInt },
        allergy: {
            type: exports.AllergyType,
            resolve: (parent) => {
                return allergies_1.Allergies.findOne({
                    where: {
                        id: parent.allergy
                    }
                });
            }
        }
    }),
});
