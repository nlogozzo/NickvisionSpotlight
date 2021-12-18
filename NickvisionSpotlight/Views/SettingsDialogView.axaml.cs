using Avalonia.Markup.Xaml;
using Avalonia.Styling;
using FluentAvalonia.UI.Controls;
using System;

namespace NickvisionSpotlight.Views
{
    public partial class SettingsDialogView : ContentDialog, IStyleable
    {
        Type IStyleable.StyleKey => typeof(ContentDialog);

        public SettingsDialogView()
        {
            AvaloniaXamlLoader.Load(this);
        }
    }
}