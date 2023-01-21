import { GraphQLObjectType, GraphQLID, GraphQLString } from "graphql";

export const TestType = new GraphQLObjectType({
  name: "All_Tests_Available",
  fields: () => ({
    id: { type: GraphQLID },
    name: { type: GraphQLString },
  }),
});

export const TestListType = new GraphQLObjectType({
  name: "All_Patient_Tests",
  fields: () => ({
    id: { type: GraphQLID },
    visit_id: { type: GraphQLID },
    test: { type: TestType },
    comments: { type: GraphQLString },
    date: { type: GraphQLString },
  }),
});