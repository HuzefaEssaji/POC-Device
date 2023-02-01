import { GraphQLObjectType, GraphQLID, GraphQLString, GraphQLInt } from "graphql";
import { Allergies } from "../../models/allergies";

export const AllergyType = new GraphQLObjectType({
  name: "Allergies",
  fields: () => ({
    id: { type: GraphQLID },
    name: { type: GraphQLString },
  }),
});

export const AllergyListType = new GraphQLObjectType({
  name: "Allergy_of_Patients",
  fields: () => ({
    id: { type: GraphQLID },
    patient_id: { type: GraphQLInt },
    allergy: {
      type: AllergyType,
      resolve: (parent) => {
        return Allergies.findOne({
          where: {
            id: parent.allergy
          }
        })
      }
    }
  }),
});

