"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.schema = void 0;
const graphql_1 = require("graphql");
const queries_1 = require("./queries/queries");
// import { CREATE_USER, DELETE_USER, UPDATE_PASSWORD } from "./mutations/user";
const RootQuery = new graphql_1.GraphQLObjectType({
    name: "RootQuery",
    fields: {
        "bloodgroups": queries_1.BloodGroupsQuery,
        "allergies": queries_1.AllergiesQuery,
        "tests": queries_1.TestsQuery,
        "prescriptions": queries_1.PrescriptionsQuery,
        "visits": queries_1.VisitsQuery,
        "patients": queries_1.PatientsQuery,
        "doctors": queries_1.DoctorsQuery,
        "getDoctorVisits": queries_1.AllVisitsByDoctor,
    },
});
// const Mutation = new GraphQLObjectType({
//   name: "Mutation",
//   fields: {
// createUser: CREATE_USER,
// deleteUser: DELETE_USER,
// updatePassword: UPDATE_PASSWORD,
//   },
// });
exports.schema = new graphql_1.GraphQLSchema({
    query: RootQuery,
    // mutation: Mutation,
});
