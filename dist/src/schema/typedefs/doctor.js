"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.DoctorsType = void 0;
const graphql_1 = require("graphql");
exports.DoctorsType = new graphql_1.GraphQLObjectType({
    name: "List_of_all_Doctors",
    fields: () => ({
        id: { type: graphql_1.GraphQLID },
        name: { type: graphql_1.GraphQLString },
        email: { type: graphql_1.GraphQLString },
        branch: { type: graphql_1.GraphQLString },
        // visits: {
        //   type: new GraphQLList(VisitsType),
        //   resolve: (doctor) => {
        //     return Visits.findAll({
        //       where: {
        //         doctor_visited: doctor.id
        //       }
        //     })
        //   }
        // },
    }),
});
