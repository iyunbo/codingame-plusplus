#include <algorithm>
#include <math.h>
#include "defibrillators.h"
#include "gtest/gtest.h"

TEST(defibrillators, nearest_should_return_string) {
    vector<string> defs;
    defs.push_back("1;Diablo;1 rue des entrepreneurs;0123456789;60;100");
    EXPECT_TRUE(nearest(defs, "1", "2").size() > 1);
}

TEST(defibrillators, should_find_the_nearest_def) {
    vector<string> defs;
    defs.push_back("1;Maison de la Prevention Sante;6 rue Maguelone 340000 Montpellier;;3,87952263361082;43,6071285339217");
    defs.push_back("2;Hotel de Ville;1 place Georges Freche 34267 Montpellier;;3,89652239197876;43,5987299452849");
    defs.push_back("3;Zoo de Lunaret;50 avenue Agropolis 34090 Mtp;;3,87388031141133;43,6395872778854");
    EXPECT_EQ(nearest(defs, "3,879483", "43,608177"), "Maison de la Prevention Sante");
}

TEST(defibrillators, should_find_the_nearest_with_exact_position) {
    vector<string> defs;
    defs.push_back("1;Maison de la Prevention Sante;6 rue Maguelone 340000 Montpellier;;3,87952263361082;43,6071285339217");
    defs.push_back("2;Hotel de Ville;1 place Georges Freche 34267 Montpellier;;3,89652239197876;43,5987299452849");
    defs.push_back("3;Zoo de Lunaret;50 avenue Agropolis 34090 Mtp;;3,87388031141133;43,6395872778854");
    defs.push_back("4;Centre municipal Garosud;34000 Montpellier;04 67 34 74 62;3,85859221929501;43,5725732056683");
    defs.push_back("35;Cimetiere Saint-lazare;2 rond-point du Souvenir Francais 34000 Montpellier;04 67 75 34 46;3,93613553570902;43,6154360341943");
    defs.push_back("36;Cimetiere Saint-Etienne;Avenue Albert Einstein 34000 Montpellier;04 99 52 87 35;3,88995587137398;43,6260090150577");
    EXPECT_EQ(nearest(defs, "3,88995587137398", "43,6260090150577"), "Cimetiere Saint-Etienne");
}

TEST(defibrillators, distance_should_be_pisitive) {
    const Location locA = {12.0, 78.0, "a"};
    const Location locB = {21.0, 42.0, "b"};
    EXPECT_GE(distance(locA, locB), 0.0);
}

TEST(defibrillators, distance_should_be_zero_for_same_position) {
    const Location locA = toLocation("36;Cimetiere Saint-Etienne;Avenue Albert Einstein 34000 Montpellier;04 99 52 87 35;3,88995587137398;43,6260090150577");
    const Location locB = {toRdians("3,88995587137398"), toRdians("43,6260090150577"), "User"};
    EXPECT_EQ(distance(locA, locB), 0.0);
}

TEST(defibrillators, distance_should_be_correct) {
    const Location locA = {1.0, 1.0, "a"};
    const Location locB = {2.0, 2.0, "b"};
    EXPECT_DOUBLE_EQ(distance(locA, locB), 6386.9195615059298);
}

TEST(defibrillators, should_split_string_into_vector_of_words) {
    EXPECT_EQ(split("1;Diablo;1 rue des entrepreneurs;0123456789;60;100", ';')[1], "Diablo");
}

TEST(defibrillators, should_convert_to_location) {
    const Location expectedLoc = {1.0, 2.0, "Diablo"};
    EXPECT_EQ(toLocation("1;Diablo;1 rue des entrepreneurs;0123456789;43,6474178784164;100"), expectedLoc);
}

TEST(defibrillators, should_consider_float_format_with_comma) {
    const string line = "1;Diablo;1 rue des entrepreneurs;0123456789;3,84329169898554;43,6474178784164";
    EXPECT_DOUBLE_EQ(toLocation(line).longitude, 3.84329169898554 * static_cast<double>(M_PI) / HALF_CIRCLE_DEGREES);
    EXPECT_DOUBLE_EQ(toLocation(line).latitude, 43.6474178784164 * static_cast<double>(M_PI) / HALF_CIRCLE_DEGREES);
}

TEST(defibrillators, should_replace_str_with_new_content) {
    EXPECT_EQ(replace("3,84329169898554", ",", "."), "3.84329169898554");
}

TEST(defibrillators, should_convert_degree_to_radians) {
    EXPECT_DOUBLE_EQ(toRdians("3.84329169898554"), 0.067078094261864479);
}

