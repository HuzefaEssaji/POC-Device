import { GraphQLObjectType, GraphQLID, GraphQLString, GraphQLInt, GraphQLList } from "graphql";
import { Visits } from "../../models/visits";
import { VisitsType } from "./visits";

export const DoctorsType = new GraphQLObjectType({
  name: "List_of_all_Doctors",
  fields: () => ({
    id: { type: GraphQLID },
    name: { type: GraphQLString },
    email: { type: GraphQLString },
    branch: { type: GraphQLString },
    visits: {
      type: new GraphQLList(VisitsType),
      resolve: (doctor) => {
        return Visits.findAll({
          where: {
            doctor_visited: doctor.id
          }
        })
      }
    },
  }),
});