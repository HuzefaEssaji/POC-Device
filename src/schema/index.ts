import { GraphQLObjectType, GraphQLSchema } from "graphql";
import { AllergiesQuery, BloodGroupsQuery, DoctorsQuery, PatientsQuery, PrescriptionsQuery, TestsQuery, VisitsQuery } from "./queries/queries";
// import { CREATE_USER, DELETE_USER, UPDATE_PASSWORD } from "./mutations/user";

const RootQuery = new GraphQLObjectType({
  name: "RootQuery",
  fields: {
    "bloodgroups": BloodGroupsQuery,
    "allergies": AllergiesQuery,
    // "patient_allergies": AllergiesListQuery,
    "tests": TestsQuery,
    "prescriptions": PrescriptionsQuery,
    "visits": VisitsQuery,
    "patients": PatientsQuery,
    "doctors": DoctorsQuery,
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

export const schema = new GraphQLSchema({
  query: RootQuery,
  // mutation: Mutation,
});