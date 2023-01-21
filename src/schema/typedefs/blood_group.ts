import { GraphQLObjectType, GraphQLID, GraphQLString } from "graphql";

export const BloodGroupType = new GraphQLObjectType({
  name: "BloodGroups",
  fields: () => ({
    id: { type: GraphQLID },
    name: { type: GraphQLString },
  }),
});
