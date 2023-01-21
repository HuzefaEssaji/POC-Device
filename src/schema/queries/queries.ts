import { GraphQLList } from "graphql";
import { Allergies } from "../../models/allergies";
import { BloodGroup } from "../../models/blood_group";
import { Doctors } from "../../models/doctor";
import { Patient } from "../../models/patient";
import { Prescription } from "../../models/prescriptions";
import { Tests } from "../../models/tests";
import { Visits } from "../../models/visits";
import { AllergyType } from "../typedefs/allergies";
import { BloodGroupType } from "../typedefs/blood_group";
import { DoctorsType } from "../typedefs/doctor";
import { PatientType } from "../typedefs/patient";
import { PrescriptionType } from "../typedefs/prescriptions";
import { TestType } from "../typedefs/tests";
import { VisitsType } from "../typedefs/visits";

export const BloodGroupsQuery = {
  type: new GraphQLList(BloodGroupType),
  resolve() {
    return BloodGroup.findAll();
  },
};

export const AllergiesQuery = {
  type: new GraphQLList(AllergyType),
  resolve() {
    return Allergies.findAll();
  },
};

export const TestsQuery = {
  type: new GraphQLList(TestType),
  resolve() {
    return Tests.findAll();
  },
};

export const PrescriptionsQuery = {
  type: new GraphQLList(PrescriptionType),
  resolve() {
    return Prescription.findAll();
  },
};

export const VisitsQuery = {
  type: new GraphQLList(VisitsType),
  resolve() {
    return Visits.findAll();
  }
}

export const PatientsQuery = {
  type: new GraphQLList(PatientType),
  resolve() {
    return Patient.findAll();
  }
}

export const DoctorsQuery = {
  type: new GraphQLList(DoctorsType),
  resolve() {
    return Doctors.findAll();
  }
}