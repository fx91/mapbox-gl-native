#pragma once

#include <mbgl/programs/circle_program.hpp>
#include <mbgl/programs/fill_program.hpp>
#include <mbgl/programs/line_program.hpp>
#include <mbgl/programs/raster_program.hpp>
#include <mbgl/programs/symbol_program.hpp>
#include <mbgl/programs/collision_box_program.hpp>

namespace mbgl {

//    std::string fragment(fragmentSource);
//    if (defines & Defines::Overdraw) {
//        assert(fragment.find("#ifdef OVERDRAW_INSPECTOR") != std::string::npos);
//        fragment.replace(fragment.find_first_of('\n'), 1, "\n#define OVERDRAW_INSPECTOR\n");
//    }

class Programs {
public:
    enum class Defines : bool {
        None = false,
        Overdraw = true,
    };

    Programs(gl::Context& context, Defines = Defines::None)
        : circle(context),
          fill(context),
          fillPattern(context),
          fillOutline(context),
          fillOutlinePattern(context),
          line(context),
          lineSDF(context),
          linePattern(context),
          raster(context),
          symbolIcon(context),
          symbolIconSDF(context),
          symbolGlyph(context),
          collisionBox(context) {
    }

    CircleProgram circle;
    FillProgram fill;
    FillPatternProgram fillPattern;
    FillOutlineProgram fillOutline;
    FillOutlinePatternProgram fillOutlinePattern;
    LineProgram line;
    LineSDFProgram lineSDF;
    LinePatternProgram linePattern;
    RasterProgram raster;
    SymbolIconProgram symbolIcon;
    SymbolSDFProgram symbolIconSDF;
    SymbolSDFProgram symbolGlyph;

    CollisionBoxProgram collisionBox;
};

} // namespace mbgl
