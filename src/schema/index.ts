import { GraphQLObjectType, GraphQLSchema } from "graphql";
// import { GET_ALL_USERS } from "./queries/user";
// import { CREATE_USER, DELETE_USER, UPDATE_PASSWORD } from "./mutations/user";

const RootQuery = new GraphQLObjectType({
  name: "RootQuery",
  fields: {
    // getAllUsers: GET_ALL_USERS,
  },
});

const Mutation = new GraphQLObjectType({
  name: "Mutation",
  fields: {
    // createUser: CREATE_USER,
    // deleteUser: DELETE_USER,
    // updatePassword: UPDATE_PASSWORD,
  },
});

export const schema = new GraphQLSchema({
  query: RootQuery,
  mutation: Mutation,
});