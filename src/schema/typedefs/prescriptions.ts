import { GraphQLObjectType, GraphQLID, GraphQLString, GraphQLInt } from "graphql";
import { Prescription } from "../../models/prescriptions";

export const PrescriptionType = new GraphQLObjectType({
  name: "All_Prescriptions_Available",
  fields: () => ({
    id: { type: GraphQLID },
    drug: { type: GraphQLString },
    dosage: { type: GraphQLString },
    interval: { type: GraphQLString },
  }),
});

export const PrescriptionListType = new GraphQLObjectType({
  name: "Patient_Prescription",
  fields: () => ({
    id: { type: GraphQLID },
    visit_id: { type: GraphQLInt },
    prescription: {
      type: PrescriptionType,
      resolve: (parent) => {
        return Prescription.findOne({
          where: {
            id: parent.prescription
          }
        })
      }
    },
  }),
});