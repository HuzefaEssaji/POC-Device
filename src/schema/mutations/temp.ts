// Queries

// import { GraphQLList } from "graphql";
// import { UserType } from "../TypeDefs/User";
// import { Users } from "../../Entities/Users";

// export const GET_ALL_USERS = {
//   type: new GraphQLList(UserType),
//   resolve() {
//     return Users.find();
//   },
// };

// Typedefs

import { GraphQLObjectType, GraphQLID, GraphQLString } from "graphql";

export const UserType = new GraphQLObjectType({
  name: "User",
  fields: () => ({
    id: { type: GraphQLID },
    name: { type: GraphQLString },
    username: { type: GraphQLString },
    password: { type: GraphQLString },
  }),
});

// Mutation

// import { GraphQLID, GraphQLString } from "graphql";
// import { UserType } from "../TypeDefs/User";
// import { Users } from "../../Entities/Users";

// export const CREATE_USER = {
//   type: UserType,
//   args: {
//     name: { type: GraphQLString },
//     username: { type: GraphQLString },
//     password: { type: GraphQLString },
//   },
//   async resolve(parent: any, args: any) {
//     const { name, username, password } = args;
//     await Users.insert({ name, username, password });
//     return args;
//   },
// };