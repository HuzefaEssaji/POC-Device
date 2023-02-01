import { GraphQLObjectType, GraphQLID, GraphQLString } from "graphql";
import { Tests } from "../../models/tests";

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
    test: {
      type: TestType,
      resolve: (parent) => {
        return Tests.findOne({
          where: {
            id: parent.test
          }
        })
      }

    },
    comments: { type: GraphQLString },
    date: { type: GraphQLString },
  }),
});