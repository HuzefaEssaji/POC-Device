"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BloodGroupType = void 0;
const graphql_1 = require("graphql");
exports.BloodGroupType = new graphql_1.GraphQLObjectType({
    name: "BloodGroups",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        name: { type: graphql_1.GraphQLString },
    }),
});
