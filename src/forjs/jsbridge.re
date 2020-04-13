open Master;
open Feedback;
open Jsaction;
open Jskeybol;

type jsInstruction = {
  actions: array(Jsaction.t),
  keybab: array(Jskeybol.t),
  feedback: string,
  nextAvailables: array(Jskeybol.t),
};

let instructionToJs = {
  let feedbackToString = f =>
    switch (f) {
    | MsgFeedback(m) => m
    | NoFeedback => ""
    };

  let toArray = (ins: Instruction.t): jsInstruction => {
    actions: ins.actions |> List.map(actionToJs) |> Array.of_list,
    keybab: ins.keybab |> List.map(keybolToJs) |> Array.of_list,
    feedback: ins.feedback |> feedbackToString,
    nextAvailables:
      ins.nextAvailables |> List.map(keybolToJs) |> Array.of_list,
  };

  ks => ks |> Instruction.instruction |> toArray;
};

let instruction = ksArr => ksArr |> Array.to_list |> instructionToJs;

module Action = {
  include Jsaction.Glossary;
};

module Keybol = {
  include Jskeybol.Glossary;
};
