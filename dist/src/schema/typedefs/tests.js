"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.TestListType = exports.TestType = void 0;
const graphql_1 = require("graphql");
const tests_1 = require("../../models/tests");
exports.TestType = new graphql_1.GraphQLObjectType({
    name: "All_Tests_Available",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        name: { type: graphql_1.GraphQLString },
    }),
});
exports.TestListType = new graphql_1.GraphQLObjectType({
    name: "All_Patient_Tests",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        visit_id: { type: graphql_1.GraphQLID },
        test: {
            type: exports.TestType,
            resolve: (parent) => {
                return tests_1.Tests.findOne({
                    where: {
                        id: parent.test
                    }
                });
            }
        },
        comments: { type: graphql_1.GraphQLString },
        date: { type: graphql_1.GraphQLString },
    }),
});
