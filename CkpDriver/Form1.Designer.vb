<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.txt_send = New System.Windows.Forms.TextBox()
        Me.txt_buf = New System.Windows.Forms.TextBox()
        Me.btn_conectar = New System.Windows.Forms.Button()
        Me.btn_desconectar = New System.Windows.Forms.Button()
        Me.btn_send = New System.Windows.Forms.Button()
        Me.cb_puertos = New System.Windows.Forms.ComboBox()
        Me.btn_actualizar = New System.Windows.Forms.Button()
        Me.bw_1 = New System.ComponentModel.BackgroundWorker()
        Me.sp_1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.txt_console = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'txt_send
        '
        Me.txt_send.Location = New System.Drawing.Point(12, 12)
        Me.txt_send.Multiline = True
        Me.txt_send.Name = "txt_send"
        Me.txt_send.Size = New System.Drawing.Size(316, 159)
        Me.txt_send.TabIndex = 1
        '
        'txt_buf
        '
        Me.txt_buf.Location = New System.Drawing.Point(12, 177)
        Me.txt_buf.Multiline = True
        Me.txt_buf.Name = "txt_buf"
        Me.txt_buf.Size = New System.Drawing.Size(316, 159)
        Me.txt_buf.TabIndex = 2
        '
        'btn_conectar
        '
        Me.btn_conectar.Location = New System.Drawing.Point(593, 12)
        Me.btn_conectar.Name = "btn_conectar"
        Me.btn_conectar.Size = New System.Drawing.Size(81, 23)
        Me.btn_conectar.TabIndex = 3
        Me.btn_conectar.Text = "Conectar"
        Me.btn_conectar.UseVisualStyleBackColor = True
        '
        'btn_desconectar
        '
        Me.btn_desconectar.Location = New System.Drawing.Point(593, 42)
        Me.btn_desconectar.Name = "btn_desconectar"
        Me.btn_desconectar.Size = New System.Drawing.Size(80, 23)
        Me.btn_desconectar.TabIndex = 4
        Me.btn_desconectar.Text = "Desconectar"
        Me.btn_desconectar.UseVisualStyleBackColor = True
        '
        'btn_send
        '
        Me.btn_send.Location = New System.Drawing.Point(593, 72)
        Me.btn_send.Name = "btn_send"
        Me.btn_send.Size = New System.Drawing.Size(81, 23)
        Me.btn_send.TabIndex = 5
        Me.btn_send.Text = "Enviar"
        Me.btn_send.UseVisualStyleBackColor = True
        '
        'cb_puertos
        '
        Me.cb_puertos.FormattingEnabled = True
        Me.cb_puertos.Location = New System.Drawing.Point(334, 12)
        Me.cb_puertos.Name = "cb_puertos"
        Me.cb_puertos.Size = New System.Drawing.Size(121, 21)
        Me.cb_puertos.TabIndex = 6
        '
        'btn_actualizar
        '
        Me.btn_actualizar.Location = New System.Drawing.Point(461, 10)
        Me.btn_actualizar.Name = "btn_actualizar"
        Me.btn_actualizar.Size = New System.Drawing.Size(71, 23)
        Me.btn_actualizar.TabIndex = 7
        Me.btn_actualizar.Text = "Actualizar"
        Me.btn_actualizar.UseVisualStyleBackColor = True
        '
        'bw_1
        '
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 1
        '
        'txt_console
        '
        Me.txt_console.BackColor = System.Drawing.SystemColors.ControlLightLight
        Me.txt_console.Location = New System.Drawing.Point(12, 342)
        Me.txt_console.Multiline = True
        Me.txt_console.Name = "txt_console"
        Me.txt_console.ReadOnly = True
        Me.txt_console.Size = New System.Drawing.Size(662, 163)
        Me.txt_console.TabIndex = 8
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(686, 517)
        Me.Controls.Add(Me.txt_console)
        Me.Controls.Add(Me.btn_actualizar)
        Me.Controls.Add(Me.cb_puertos)
        Me.Controls.Add(Me.btn_send)
        Me.Controls.Add(Me.btn_desconectar)
        Me.Controls.Add(Me.btn_conectar)
        Me.Controls.Add(Me.txt_buf)
        Me.Controls.Add(Me.txt_send)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txt_send As System.Windows.Forms.TextBox
    Friend WithEvents txt_buf As System.Windows.Forms.TextBox
    Friend WithEvents btn_conectar As System.Windows.Forms.Button
    Friend WithEvents btn_desconectar As System.Windows.Forms.Button
    Friend WithEvents btn_send As System.Windows.Forms.Button
    Friend WithEvents cb_puertos As System.Windows.Forms.ComboBox
    Friend WithEvents btn_actualizar As System.Windows.Forms.Button
    Friend WithEvents bw_1 As System.ComponentModel.BackgroundWorker
    Friend WithEvents sp_1 As System.IO.Ports.SerialPort
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents txt_console As System.Windows.Forms.TextBox

End Class
