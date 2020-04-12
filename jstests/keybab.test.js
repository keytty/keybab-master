const keybab = require("../src/forjs/jsbridge.bs.js");

const {
  instruction,
  Action: { move },
  Command: { j },
} = keybab;

describe("instruction", () => {
  test("['j', 'x'] with reference", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          coordinates: { vertical: -1, horizontal: 0 },
          type: move,
        },
      ],
      commands: [j],
      feedback: "x is undefined",
      nextAvailables: [j],
    });
  });

  test("['j', 'x'] with string", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          coordinates: { vertical: -1, horizontal: 0 },
          type: "move",
        },
      ],
      commands: ["j"],
      feedback: "x is undefined",
      nextAvailables: ["j"],
    });
  });
});
