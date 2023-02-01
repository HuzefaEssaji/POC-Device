import { GraphQLObjectType, GraphQLSchema } from "graphql";
import { AllergiesQuery, AllVisitsByDoctor, BloodGroupsQuery, DoctorsQuery, PatientsQuery, PrescriptionsQuery, TestsQuery, VisitsQuery } from "./queries/queries";
// import { CREATE_USER, DELETE_USER, UPDATE_PASSWORD } from "./mutations/user";

const RootQuery = new GraphQLObjectType({
  name: "RootQuery",
  fields: {
    "bloodgroups": BloodGroupsQuery,
    "allergies": AllergiesQuery,
    "tests": TestsQuery,
    "prescriptions": PrescriptionsQuery,
    "visits": VisitsQuery,
    "patients": PatientsQuery,
    "doctors": DoctorsQuery,
    "getDoctorVisits": AllVisitsByDoctor,
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