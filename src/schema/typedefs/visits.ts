import { GraphQLObjectType, GraphQLID, GraphQLString, GraphQLInt, GraphQLList } from "graphql";
import { Doctors } from "../../models/doctor";
import { PrescriptionList } from "../../models/prescriptions";
import { TestsList } from "../../models/tests";
import { DoctorsType } from "./doctor";
import { PrescriptionListType } from "./prescriptions";
import { TestListType } from "./tests";

export const VisitsType = new GraphQLObjectType({
  name: "All_of_the_Visits",
  fields: () => ({
    id: { type: GraphQLID },
    patient: { type: GraphQLInt },
    date: { type: GraphQLString },
    weight: { type: GraphQLString },
    height: { type: GraphQLString },
    temperature: { type: GraphQLString },
    bp: { type: GraphQLString },
    ecg: { type: GraphQLString },
    prescriptions: {
      type: new GraphQLList(PrescriptionListType),
      resolve: (visit) => {
        return PrescriptionList.findAll({
          where: {
            visit_id: visit.id
          }
        })
      }
    },
    tests: {
      type: new GraphQLList(TestListType),
      resolve: (visit) => {
        return TestsList.findAll({
          where: {
            visit_id: visit.id
          }
        })
      }
    },
    doctor_visited: {
      type: DoctorsType,
      resolve: (parent) => {
        return Doctors.findOne({
          where: {
            id: parent.doctor_visited
          }
        })
      }
    }
  }),
});
