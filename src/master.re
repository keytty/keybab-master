module Instruction = {
  type t = {
    actions: list(Action.t),
    keybab: list(Keybol.t),
    feedback: Feedback.t,
    nextAvailables: list(Keybol.t),
  };

  let instruction = {
    open Keybol;
    open Feedback;
    open Action;
    open Keybab;

    let feedbackForLastKeybol = cs =>
      cs |> List.rev |> List.hd |> feedbackForKeybol;

    let instructionFromKeybab = cs => {
      actions: cs |> validActions,
      keybab: cs |> validKeybab,
      feedback: cs |> feedbackForLastKeybol,
      nextAvailables: [J, ...allDigitKeybols],
    };

    ks => ks |> List.map(keyToKeybol) |> instructionFromKeybab;
  };
};
