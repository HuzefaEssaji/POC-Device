"use strict";
// Queries
Object.defineProperty(exports, "__esModule", { value: true });
exports.UserType = void 0;
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
const graphql_1 = require("graphql");
exports.UserType = new graphql_1.GraphQLObjectType({
    name: "User",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        name: { type: graphql_1.GraphQLString },
        username: { type: graphql_1.GraphQLString },
        password: { type: graphql_1.GraphQLString },
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
