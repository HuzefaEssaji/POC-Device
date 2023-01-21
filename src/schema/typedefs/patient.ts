import { GraphQLObjectType, GraphQLID, GraphQLString, GraphQLInt, GraphQLList } from "graphql";
import { AllergiesList } from "../../models/allergies";
import { Visits } from "../../models/visits";
import { AllergyListType } from "./allergies";
import { BloodGroupType } from "./blood_group";
import { VisitsType } from "./visits";

export const PatientType = new GraphQLObjectType({
  name: "All_of_the_Patients",
  fields: () => ({
    id: { type: GraphQLID },
    uid: { type: GraphQLInt },
    name: { type: GraphQLString },
    aadhar: { type: GraphQLString },
    email: { type: GraphQLString },
    father_name: { type: GraphQLString },
    mother_name: { type: GraphQLString },
    address: { type: GraphQLString },
    date_of_birth: { type: GraphQLString },
    blood_group: { type: BloodGroupType },
    allergies: {
      type: new GraphQLList(AllergyListType),
      resolve: (patient) => {
        return AllergiesList.findAll({
          where: {
            patient_id: patient.id
          }
        })
      }
    },
    current_weight: { type: GraphQLString },
    current_height: { type: GraphQLString },
    gender: { type: GraphQLString },
    city: { type: GraphQLString },
    pin: { type: GraphQLString },
    state: { type: GraphQLString },
    visits: {
      type: new GraphQLList(VisitsType),
      resolve: (patient) => {
        return Visits.findAll({
          where: {
            patient: patient.id
          }
        })
      }
    }
  }),
});
